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
#endif