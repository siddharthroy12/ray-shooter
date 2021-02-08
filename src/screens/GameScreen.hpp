#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include "../Node.hpp"
#include <string>
#include "raylib.h"

class GameScreen : public Node {
    private:
    Texture texture;
    Rectangle sourceRec;
    Rectangle destRec;
    Vector2 origin;
    public:
        int kills = 0;
        std::string name() { return "GameScreen"; }
        GameScreen(Node *parent);
        ~GameScreen();
        void render();
        void update();
        void pause();
};

#endif