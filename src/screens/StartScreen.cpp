#include "StartScreen.hpp"
#include "raylib.h"
#include "../context/GlobalContext.hpp"
#include "../Globals.hpp"
#include "GameScreen.hpp"

StartScreen::StartScreen(Node* parent) : Node(parent) {
    this->textRec.width = (MeasureTextEx(GetFontDefault(), this->text, 30, 2)).x + 4;
    this->textRec.height = (MeasureTextEx(GetFontDefault(), this->text, 30, 2)).y;
    this->textRec.x = (SCREEN_WIDTH / 2) - (this->textRec.width / 2);

    this->exitRec.width = (MeasureTextEx(GetFontDefault(), "Exit", 30, 2)).x + 4;
    this->exitRec.height = (MeasureTextEx(GetFontDefault(), "Exit", 30, 2)).y + 1;
    this->exitRec.x = (SCREEN_WIDTH / 2) - (this->exitRec.width) - 20;

    this->againRec.width = (MeasureTextEx(GetFontDefault(), "Play", 30, 2)).x + 4;
    this->againRec.height = (MeasureTextEx(GetFontDefault(), "Play", 30, 2)).y + 1;
    this->againRec.x = (SCREEN_WIDTH / 2) + 10;
}

void StartScreen::render() {
    ClearBackground(WHITE);
    
    DrawTextRec(GetFontDefault(), this->text, this->textRec, 30, 2, false, { 34, 32, 52, 255 });
    Rectangle tmp = textRec;
    tmp.x -= 7;
    tmp.y -= 5;
    tmp.width += 10;
    tmp.height += 8;
    DrawRectangleLinesEx((tmp), 2, { 34, 32, 52, 255 });

    DrawTextRec(GetFontDefault(), "Exit", this->exitRec, 30, 2, false, RED);
    tmp = exitRec;
    tmp.x -= 5;
    tmp.y -= 2;
    tmp.width += 7;
    tmp.height += 2;
    DrawRectangleLinesEx(tmp, 2, RED);

    tmp = againRec;
    tmp.x -= 5;
    tmp.y -= 2;
    tmp.width += 7;
    tmp.height += 2;
    DrawRectangleRec(tmp, LIME);
    DrawTextRec(GetFontDefault(), "Play", this->againRec, 30, 2, false, RAYWHITE);
    
    

    DrawRectangle(0,0, MeasureText((std::string("Your Highscore: ") + std::to_string(globalState->highscore)).c_str(), 30) + 10, 32, { 34, 32, 52, 255 });
    DrawText((std::string("Your Highscore: ") + std::to_string(globalState->highscore)).c_str(), 4, 2, 30, WHITE);
}

void StartScreen::update() {
    if (CheckCollisionPointRec(GetMousePosition(), exitRec)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            globalState->setRootnode(NULL);
        }
    }

    if (CheckCollisionPointRec(GetMousePosition(), againRec)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            globalState->setRootnode(new GameScreen(NULL));
        }
    }
}

StartScreen::~StartScreen() {}