#ifndef START_SCREEN_HPP
#define START_SCREEN_HPP

#include "../Node.hpp"
#include "raylib.h"

class StartScreen : public Node {
    private:
        char* text = "Ray Shooter";
        Rectangle exitRec = { 2, 250, 50, 20 };
        Rectangle textRec = { 20, 150, 5, 29 };
        Rectangle againRec = { 2, 250, 50, 20 };
    public:
    std::string name() { return "StartScreen"; }
    StartScreen(Node *parent);
    ~StartScreen();
    void update();
    void render();
};

#endif