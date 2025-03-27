#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "BinaryTree.h"
using namespace std;

TEST_CASE("Insertion of nodes.") {
    Node<int>* t1 = new Node<int>(6, new Node<int>(5), new Node<int>(11));
    Node<int>* t2 = new Node<int>(9, new Node<int>(5), nullptr);
    Node<int>* t3 = new Node<int>(7, new Node<int>(2), t1);
    Node<int>* t4 = new Node<int>(9, nullptr, t2);
    Node<int>* tree = new Node<int>(1, t3, t4);
    
}