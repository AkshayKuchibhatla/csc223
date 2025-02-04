#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "LinkedList.h"
using namespace std;

// Renders the linked list
// @param n: the first node of the list
// @param s: a string to which the list elements will be appended
string renderList(Node* n, string s) {
    s += n->to_str();
    if (n->nextNode != nullptr) {
        s += ", ";
        return renderList(n->nextNode, s);
    }
    return s;
}
// Renders the linked list in reverse
// @param n: the first node of the list
// @param s: a string to which the list elements will be appended
string renderListReverse(Node* n, string s) {
    s = n->to_str() + s;
    if (n->nextNode != nullptr) {
        s = ", " + s;
        return renderListReverse(n->nextNode, s);
    }
    return s;
}
// Renders the linked list with parentheses around it
// @param n: the first node of the list
// @param s: a string to which the list elements will be appended
// @param reverse: indicates whether or not the list will be printed in reverse.
string renderListPretty(Node* n, string s, bool reverse) {
    // string startP = "(";
    // string endP = ")";
    if (reverse) {
        return "(" + renderListReverse(n, s) + ")";
    } else {
        return "(" + renderList(n, s) + ")";
    }
}
// Removes the second element of the list and then returns a pointer to it
// @param n: the first node of the list
Node* removeSecond(Node* n) {
    Node* first = n;
    Node* second = n->nextNode;
    first->nextNode = second->nextNode;
    second->nextNode = nullptr;
    return second;
}


TEST_CASE("Test creation and rendering of List Nodes") {
    Node* n1 = new Node();
    CHECK(n1->cargo == 0);
    Node* n2 = new Node(74);
    CHECK(n2->cargo == 74);
    CHECK(n1->to_str() == "0");
    CHECK(n2->to_str() == "74");
}
TEST_CASE("Test the linking of nodes.") {
    Node* n3 = new Node(30);
    Node* n2 = new Node(20, n3);
    Node* n1 = new Node(10, n2);
    CHECK(n1->nextNode == n2);
    CHECK(n1->nextNode->nextNode == n3);
}
TEST_CASE("Test the display of linked nodes.") {
    Node* n4 = new Node(40);
    Node* n3 = new Node(30, n4);
    Node* n2 = new Node(20, n3);
    Node* n1 = new Node(10, n2);
    CHECK(renderList(n1, "") == "10, 20, 30, 40");
    CHECK(renderListReverse(n1, "") == "40, 30, 20, 10");
}
TEST_CASE("Test prettier rendering.") {
    Node* n4 = new Node(40);
    Node* n3 = new Node(30, n4);
    Node* n2 = new Node(20, n3);
    Node* n1 = new Node(10, n2);
    CHECK(renderListPretty(n1, "", false) == "(10, 20, 30, 40)");
    CHECK(renderListPretty(n1, "", true) == "(40, 30, 20, 10)");
}
TEST_CASE("Test removeSecond() function.") {
    Node* n4 = new Node(40);
    Node* n3 = new Node(30, n4);
    Node* n2 = new Node(20, n3);
    Node* n1 = new Node(10, n2);
    Node* deletedNode = removeSecond(n1);
    CHECK(deletedNode->cargo == 20);
    CHECK(renderListPretty(n1, "", false) == "(10, 30, 40)");
}