#ifndef GLOBAL_STATE_HPP
#define GLOBAL_STATE_HPP

#include "../Node.hpp"

class GlobalState {
    public:
        Node* changeTo = NULL;
        bool change = false;
        Node* rootNode;
        int highscore = 0;
        void setRootnode(Node* node);
        GlobalState();
        ~GlobalState();
};

#endif