#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "Queue.h"
using namespace std;

TEST_CASE("Testing ArrayQueue operations") {
    ArrayQueue<int> q;
    CHECK(q.empty() == true);
    for (int i = 1; i < 10; i++) {
        q.enqueue(i);
    }
    CHECK(q.empty() == false);
    CHECK_THROWS_WITH(q.enqueue(11), "Error: No more space in queue.");
    for (int i = 1; i < 10; i++) {
        CHECK(q.dequeue() == i);
    }
    
    CHECK(q.empty() == true);
    CHECK_THROWS_WITH(q.dequeue(), "Error: Cannot dequeue from empty queue.");
}

TEST_CASE("Testing LinkedList queue operations") {
    Queue<int> q;
    CHECK(q.empty() == true);
    for (int i = 1; i < 10; i++) {
        q.enqueue(i);
    }
    CHECK(q.empty() == false);
    for (int i = 1; i < 10; i++) {
        CHECK(q.dequeue() == i);
    }
    CHECK(q.empty() == true);
    CHECK_THROWS_WITH(q.dequeue(), "Error: Cannot dequeue from empty queue.");
}

