#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H
#include <string>
using namespace std;

struct Node {
    int cargo;
    Node* nextNode;

    Node();
    Node(int c);
    Node(int c, Node* n);
    string to_str() const;
};

class LinkedList {
    int numNodes;
    Node* front;

    public:
        LinkedList();

        // Inserts a new node at the front of the linked list.
        // @param c: the cargo of the new node
        void insertFront(int c);
};
#endif