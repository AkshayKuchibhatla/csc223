#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "LinkedList.h"
using namespace std;

TEST_CASE("Test creation of empty list.") {
    OrderedLinkedList<int>* olnkdlst = new OrderedLinkedList<int>();
    CHECK(olnkdlst->getHead() == nullptr);
    CHECK(olnkdlst->size() == 0);
}
TEST_CASE("Test ordering of elements.") {
    OrderedLinkedList<int>* olnkdlst = new OrderedLinkedList<int>();
    olnkdlst->addItem(20);
    olnkdlst->addItem(10);
    olnkdlst->addItem(40);
    olnkdlst->addItem(30);
    olnkdlst->addItem(35);
    CHECK(olnkdlst->getHead()->getCargo() == 10);
    CHECK(olnkdlst->to_string() == "(10, 20, 30, 35, 40)");
    CHECK(olnkdlst->to_string_reverse() == "(40, 35, 30, 20, 10)");
}