#ifndef GAME_OVER_HPP
#define GAME_OVER_HPP

#include "../Node.hpp"
#include "raylib.h"

class GameOver : public Node {
    private:
        char* text = "Game Over";
        Rectangle exitRec = { 2, 250, 50, 20 };
        Rectangle textRec = { 20, 150, 5, 29 };
        Rectangle againRec = { 2, 250, 50, 20 };
    public:
    std::string name() { return "GameOverScreen"; }
    GameOver(Node *parent);
    ~GameOver();
    void update();
    void render();
};

#endif