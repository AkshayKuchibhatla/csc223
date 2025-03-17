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
    for (int i = 0; i < 4; i++) {
        q.dequeue();
    }
    CHECK_THROWS_WITH(q.dequeue(), "Error: Cannot dequeue from empty queue.");
}

TEST_CASE("Test ArrayPriorityQueue adding, removal and top().") {
    ArrayPriorityQueue<int> apq;
    apq.enqueue(4);
    apq.enqueue(7);
    apq.enqueue(3);
    apq.enqueue(2);
    CHECK_THROWS_WITH(apq.enqueue(10), "Error: No more space in queue.");
    CHECK(apq.top() == 7);
    CHECK(apq.dequeue() == 7);
    CHECK(apq.dequeue() == 4);
    CHECK(apq.dequeue() == 3);
    CHECK(apq.dequeue() == 2);
    CHECK_THROWS_WITH(apq.dequeue(), "Error: Cannot dequeue from empty queue.");
}