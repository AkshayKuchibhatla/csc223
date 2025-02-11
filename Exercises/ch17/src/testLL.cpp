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
TEST_CASE("Test to_string_reverse()") {
    LinkedList<int>* lnklst = new LinkedList<int>();
    lnklst->addFirst(10);
    lnklst->addFirst(20);
    lnklst->addFirst(30);
    lnklst->addFirst(40);
    CHECK(lnklst->size() == 4);
    CHECK(lnklst->to_string_reverse() == "(10, 20, 30, 40)");
}
TEST_CASE("Test string comparison") {
    CHECK("string1" > "string2");
}