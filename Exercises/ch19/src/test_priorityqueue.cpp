#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "PriorityQueue.h"
using namespace std;

TEST_CASE("Test adding of items.") {
    PriorityQueue<int> q;
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(9);
    CHECK(q.to_string() == "(9, 7, 4, 3, 2)");
}
TEST_CASE("Test removal of items and top().") {
    PriorityQueue<int> q;
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(9);
    CHECK(q.dequeue() == 9);
    CHECK(q.top() == 7);
}

