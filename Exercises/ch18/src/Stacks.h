#include "../../ch17/src/LinkedList.h"

template <class T>
class Stack : public LinkedList<T> {
    public:
        void push(T item) {
            LinkedList<T>::addFirst(item);
        }
        T pop() {
            return LinkedList<T>::removeFront();
        }
        bool empty() const {
            return LinkedList<T>::empty();
        }
        T top() {
            if (LinkedList<T>::empty())
                throw runtime_error("Cannot return top item of empy stack.");
            return LinkedList<T>::getHead()->getCargo();
        }
};