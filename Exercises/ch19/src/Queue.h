#pragma once
#include "../../ch17/src/LinkedList.h"
#define MAX_SIZE 10

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
class ArrayQueue {
    private:
        int first;
        int last;
        int numNodes;
        T items[sizeof(T) * MAX_SIZE];
    public:
        ArrayQueue() {
            first = 0; // first and last store where exactly the items are in the array
            last = 0;
            numNodes = 0;
        }
        void enqueue(T cargo) {
            
        }
};