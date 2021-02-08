#include "GameOver.hpp"
#include "raylib.h"
#include "../context/GlobalContext.hpp"
#include "../Globals.hpp"
#include "GameScreen.hpp"

GameOver::GameOver(Node* parent) : Node(parent) {
    this->textRec.width = (MeasureTextEx(GetFontDefault(), this->text, 30, 2)).x + 4;
    this->textRec.height = (MeasureTextEx(GetFontDefault(), this->text, 30, 2)).y;
    this->textRec.x = (SCREEN_WIDTH / 2) - (this->textRec.width / 2);

    this->exitRec.width = (MeasureTextEx(GetFontDefault(), "Exit", 30, 2)).x + 4;
    this->exitRec.height = (MeasureTextEx(GetFontDefault(), "Exit", 30, 2)).y + 1;
    this->exitRec.x = (SCREEN_WIDTH / 2) - (this->exitRec.width) - 60;

    this->againRec.width = (MeasureTextEx(GetFontDefault(), "Play Again", 30, 2)).x + 4;
    this->againRec.height = (MeasureTextEx(GetFontDefault(), "Play Again", 30, 2)).y + 1;
    this->againRec.x = (SCREEN_WIDTH / 2) - 30;
}

void GameOver::render() {
    ClearBackground(WHITE);
    
    DrawTextRec(GetFontDefault(), this->text, this->textRec, 30, 2, false, BLACK);
    Rectangle tmp = textRec;
    tmp.x -= 7;
    tmp.y -= 5;
    tmp.width += 10;
    tmp.height += 8;
    DrawRectangleLinesEx((tmp), 2, BLACK);

    DrawTextRec(GetFontDefault(), "Exit", this->exitRec, 30, 2, false, RED);
    tmp = exitRec;
    tmp.x -= 5;
    tmp.y -= 2;
    tmp.width += 7;
    tmp.height += 2;
    DrawRectangleLinesEx(tmp, 2, RED);

    DrawTextRec(GetFontDefault(), "Play Again", this->againRec, 30, 2, false, RED);
    tmp = againRec;
    tmp.x -= 5;
    tmp.y -= 2;
    tmp.width += 7;
    tmp.height += 2;
    DrawRectangleLinesEx(tmp, 2, RED);

    DrawText((std::string("Your Highscore: ") + std::to_string(globalState->highscore)).c_str(), 4, 2, 30, RED);

}

void GameOver::update() {
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

GameOver::~GameOver() {}