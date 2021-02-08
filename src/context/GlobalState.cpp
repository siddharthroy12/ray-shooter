#include "GlobalState.hpp"
#include "../screens/StartScreen.hpp"

GlobalState::GlobalState() {
    this->rootNode = new StartScreen(NULL);
    this->highscore = LoadStorageValue(1);

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
    SaveStorageValue(1, this->highscore);
}