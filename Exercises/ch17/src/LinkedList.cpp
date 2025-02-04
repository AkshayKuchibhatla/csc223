#include <string>
#include "LinkedList.h"
using namespace std;

// Default constructor
Node::Node() {
    cargo = 0;
    nextNode = nullptr;
}
// @param c: the cargo of the new node.
Node::Node(int c) {
    this->cargo = c;
    this->nextNode = nullptr;
}
// @param c: the cargo of the new node.
// @param n: pointer to the next node.
Node::Node(int c, Node* n) {
    this->cargo = c;
    this->nextNode = n;
}

string Node::to_str() const {
    return to_string(cargo);
}
// Renders the linked list backwards
// @param n: the first node of the list
string renderListReverse(Node* n) {
    string renderedReverseList = "";
    renderedReverseList.append(n->to_str());
    renderedReverseList.append(", ");
    while (n->nextNode != nullptr) {
        renderedReverseList = n->nextNode->to_str() + ", " + renderedReverseList;
        n = n->nextNode;
    }
    return renderedReverseList;
}