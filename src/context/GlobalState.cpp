#include "GlobalState.hpp"
#include "../screens/GameScreen.hpp"

GlobalState::GlobalState() {
    this->rootNode = new GameScreen(NULL);
}

void GlobalState::setRootnode(Node *node) {
    this->changeTo = node;
    this->change = true;
}

GlobalState::~GlobalState() {
    if (this->rootNode != NULL) {
        delete rootNode;
        rootNode = NULL;
    }
}