#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "LinkedList.h"
using namespace std;

TEST_CASE("Test creation and empty list.") {
    CircleLinkedList<int>* clnkdlst = new CircleLinkedList<int>();
    CHECK(clnkdlst->to_string() == "Empty list");
    CHECK(clnkdlst->getHead() == nullptr);
    CHECK(clnkdlst->getTail() == nullptr);
    CHECK(clnkdlst->size() == 0);
}
TEST_CASE("Test one node.") {
    CircleLinkedList<int>* clnkdlst = new CircleLinkedList<int>();
    clnkdlst->addNode(10);
    CHECK(clnkdlst->size() == 1);
    CHECK(clnkdlst->getHead()->getCargo() == 10);
    CHECK(clnkdlst->getTail() == clnkdlst->getHead());
}