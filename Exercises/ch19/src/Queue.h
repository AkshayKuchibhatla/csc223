#pragma once
#include "../../ch17/src/LinkedList.h"
#define MAX_ITEMS 10 // The maximum number of items that can go inside the ArrayQueue
#include <string>
using namespace std;

template <class T>
class Queue : public LinkedList<T> { // LinkedList implementation of queue
    public:
        // Constructor
        Queue() = default;

        // Modifiers
        void enqueue(T cargo) {
            LinkedList<T>::addEnd(cargo);
        }
        T dequeue() {
            if (size() == 0)
                throw underflow_error("Error: Cannot dequeue from empty queue.");
            return LinkedList<T>::removeFront();
        }
        int size() {
            return LinkedList<T>::size();
        }
        bool empty() {
            return (LinkedList<T>::size() == 0);
        }
};

template <class T>
class ArrayQueue { // Implementation of queue using C array
    private:
        int first;
        int last;
        T items[MAX_ITEMS];
    public:
        ArrayQueue() {
            first = 0; // first and last store where exactly the items are in the array
            last = 0;
        }
        void enqueue(const T& val) {
            if ((last + 1) % MAX_ITEMS == first) {
                throw overflow_error("Error: No more space in queue.");
            }
            items[last] = val;
            last = (last + 1) % MAX_ITEMS;
        }
        T dequeue() {
            if (empty())
                throw underflow_error("Error: Cannot dequeue from empty queue.");
            
            int old1st = first;
            first = (first + 1) % MAX_ITEMS;
            return items[old1st];
        }
        bool empty() const {
            return (first == last);
        }

};