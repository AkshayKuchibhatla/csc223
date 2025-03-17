# Priority Queues in Array and LinkedList Form

By Trostin, Adonis and Akshay

- The priority queue is just like a normal queue, save for the fact that its elements are arranged in a specific order.
- This means that the only function that needs to be changed is the `enqueue()` function, because if elements are added in order they will also obviously be dequeued in order.

## Implementations

So, here are the implementations of the function that we came up with:

**Linked list version:**

```C++
void enqueue(T cargo) {
    if (LinkedList<T>::length() == 0) {
        LinkedList<T>::insert_at_front(cargo);
    } else {
        int n = 1;
        while (n <= LinkedList<T>::length() && LinkedList<T>::get_item_at(n) > cargo) {
            n++;
        }
        LinkedList<T>::insert_item_at(cargo, n - 1);
    }
}
```

- The linked list implementation simply needs to insert in the middle by linking the correct nodes together
- This is done in the `insert_at_front()` function that we were provided.

**Array version:**

```C++
void enqueue(const T& val) {
    if ((last + 1) % MAX_ITEMS == first) {
        throw overflow_error("Error: No more space in queue.");
    }
    items[last] = val;
    int index1 = last;
    last = (last + 1) % MAX_ITEMS;
    length++;
    if (length == 1) return;

    int index2 = (index1 == 0) ? MAX_ITEMS - 1 : index1 - 1;
    T tempItem;
    int swapCounter = 1;
    while (items[index1] > items[index2] && swapCounter < length) {
        tempItem = items[index1];
        items[index1] = items[index2];
        items[index2] = tempItem;
        swapCounter++;

        index2 = (index2 == 0) ? MAX_ITEMS - 1 : index2 - 1;
        index1 = (index1 == 0) ? MAX_ITEMS - 1 : index1 - 1;
    }
}
```

- The array version, on the other hand, has to shift all of the elements that came before it by one slot
- The algorithm above accomplishes this by initially adding the new item to the end of the queue before traversing the queue backwards and swapping places with every element that is less than it

## Tests

Finally, the tests for this data structure are quite similar to those of the regular queue, the exception being that they must check the order of the inserted elements. We have displayed our tests below:

**Linked list version tests:**

```C++
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
```

**Array version tests:**

```C++
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
```

## Sources

- [What is Priority Queue | Introduction to Priority Queue](https://www.geeksforgeeks.org/priority-queue-set-1-introduction/)
