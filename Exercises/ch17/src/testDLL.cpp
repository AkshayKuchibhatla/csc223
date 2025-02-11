#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "LinkedList.h"
using namespace std;

TEST_CASE("Test Creation and empty list.") {
    DoubleLinkedList<int>* dlnklst = new DoubleLinkedList<int>();
    CHECK(dlnklst->to_string() == "Empty list");
    CHECK(dlnklst->to_string_reverse() == "Empty list");
}
TEST_CASE("Test forward linking.") {
    DoubleLinkedList<int>* dlnklst = new DoubleLinkedList<int>();
    dlnklst->addFirst(10);
    dlnklst->addFirst(20);
    dlnklst->addFirst(30);
    dlnklst->addFirst(40);
    CHECK(dlnklst->getHead()->getCargo() == 40);
    CHECK(dlnklst->getHead()->getNext()->getCargo() == 30);
    CHECK(dlnklst->getHead()->getNext()->getNext()->getCargo() == 20);
}
TEST_CASE("Test backward linking.") {
    DoubleLinkedList<int>* dlnklst = new DoubleLinkedList<int>();
    dlnklst->addFirst(10);
    dlnklst->addFirst(20);
    dlnklst->addFirst(30);
    dlnklst->addFirst(40);
    DoubleNode<int>* lastNode = dlnklst->getHead()->getNext()->getNext()->getNext();
    CHECK(lastNode->getCargo() == 10);
    CHECK(lastNode->getPrev()->getCargo() == 20);
    CHECK(lastNode->getPrev()->getPrev()->getCargo() == 30);
    CHECK(lastNode->getPrev()->getPrev()->getPrev() == dlnklst->getHead());
}
TEST_CASE("Test to_string() and to_string_reverse().") {
    DoubleLinkedList<int>* dlnklst = new DoubleLinkedList<int>();
    dlnklst->addFirst(10);
    dlnklst->addFirst(20);
    dlnklst->addFirst(30);
    dlnklst->addFirst(40);
    CHECK(dlnklst->to_string() == "(40, 30, 20, 10)");
    CHECK(dlnklst->to_string_reverse() == "(10, 20, 30, 40)");
}
