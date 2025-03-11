#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "Queue.h"
using namespace std;

TEST_CASE("Test basic queue operations on queue of strings") {
    ArrayQueue<string> queue;
    CHECK(queue.empty() == true);
    queue.enqueue("first");
    CHECK(queue.empty() == false);
    queue.enqueue("second");
    queue.enqueue("third");
    CHECK(queue.dequeue() == "first");
    queue.enqueue("forth");
    queue.enqueue("fifth");
    queue.enqueue("sixth");
    queue.enqueue("seventh");
    queue.enqueue("eight");
    queue.enqueue("nineth");
    CHECK(queue.dequeue() == "second");
    CHECK(queue.dequeue() == "third");
    queue.enqueue("tenth");
    queue.enqueue("eleventh");
    CHECK(queue.dequeue() == "forth");
    queue.enqueue("twelfth");
    queue.enqueue("thirteenth");
    CHECK(queue.dequeue() == "fifth");
}

TEST_CASE("Test queue handles overflow and underflow") {
    ArrayQueue<int> q;
    for (int i = 1; i < 10; i++) {
        q.enqueue(i);
    }
    CHECK(q.empty() == false);
    CHECK_THROWS_WITH(q.enqueue(11), "Error: No more space in queue.");
    for (int i = 1; i < 10; i++)
        CHECK(q.dequeue() == i);
    CHECK_THROWS_WITH(q.dequeue(), "Error: Cannot dequeue from empty queue.");
}