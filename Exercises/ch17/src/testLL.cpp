#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "LinkedList.h"
using namespace std;

TEST_CASE("Test creation and rendering of List Nodes") {
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