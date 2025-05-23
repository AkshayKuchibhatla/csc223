#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "LinkedList.h"
using namespace std;

TEST_CASE("Test creation of empty list.") {
    LinkedList<int>* lnklst = new LinkedList<int>();
    CHECK(lnklst->getHead() == nullptr);
    CHECK(lnklst->to_string() == "Empty list");
}
TEST_CASE("Test creation and rendering of List Nodes.") {
    LinkedList<int>* lnklst = new LinkedList<int>();
    lnklst->addFirst(10);
    CHECK(lnklst->to_string() == "(10)");
}
TEST_CASE("Test the linking of nodes.") {
    LinkedList<int>* lnklst = new LinkedList<int>();
    lnklst->addFirst(10);
    lnklst->addFirst(20);
    CHECK(lnklst->to_string() == "(20, 10)");
}
TEST_CASE("Test removeFront() function.") {
    LinkedList<int>* lnklst = new LinkedList<int>();
    lnklst->addFirst(10);
    lnklst->addFirst(20);
    lnklst->addFirst(30);
    lnklst->addFirst(40);
    CHECK(lnklst->removeFront() == 40);
    CHECK(lnklst->to_string() == "(30, 20, 10)");
}
TEST_CASE("Test addEnd() function.") {
    LinkedList<int>* lnklst = new LinkedList<int>();
    lnklst->addEnd(10);
    lnklst->addEnd(20);
    lnklst->addEnd(30);
    lnklst->addEnd(40);
    CHECK(lnklst->to_string() == "(10, 20, 30, 40)");
}
TEST_CASE("Test insertAt() function.") {
    LinkedList<int>* lnklst = new LinkedList<int>();
    lnklst->addEnd(10);
    lnklst->addEnd(20);
    lnklst->addEnd(30);
    lnklst->addEnd(40);
    lnklst->insertAt(15, 1);
    CHECK(lnklst->to_string() == "(10, 15, 20, 30, 40)");
    CHECK_THROWS_WITH(lnklst->insertAt(45, 6), "Error: insertAt() index out of bounds.");
}
TEST_CASE("Test getAt() function.") {
    LinkedList<int>* lnklst = new LinkedList<int>();
    lnklst->addEnd(10);
    lnklst->addEnd(20);
    lnklst->addEnd(30);
    lnklst->addEnd(40);
    CHECK(lnklst->getAt(3) == 40);
}
TEST_CASE("Test removeAt() function.") {
    LinkedList<int>* lnklst = new LinkedList<int>();
    lnklst->addEnd(10);
    lnklst->addEnd(20);
    lnklst->addEnd(30);
    lnklst->addEnd(40);
    CHECK_THROWS_WITH(lnklst->removeAt(4), "Error: removeAt() index out of bounds.");
}
TEST_CASE("Test to_string_reverse()") {
    LinkedList<int>* lnklst = new LinkedList<int>();
    lnklst->addFirst(10);
    lnklst->addFirst(20);
    lnklst->addFirst(30);
    lnklst->addFirst(40);
    CHECK(lnklst->size() == 4);
    CHECK(lnklst->to_string_reverse() == "(10, 20, 30, 40)");
}