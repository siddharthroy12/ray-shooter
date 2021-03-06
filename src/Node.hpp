#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <string>

class Node {
    private:
        bool deleteOnNextRender = false;
    public:
    virtual void pause();
    virtual void update() { } ;
    virtual void render() { };
    void _pause();
    void _update();
    void _render();
    
    Node(Node *parent);
    void deleteThis();
    bool paused = false;
    virtual std::string name() { return "Node"; }
    std::vector<Node*> childrens;
    Node* getChildren(std::string name);
    Node* parent;
    
    virtual ~Node();
    Node* updateAndRender();
};

#endif