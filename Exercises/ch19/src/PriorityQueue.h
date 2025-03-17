#include "ElknerLinkedList.h"
#include <string>
using namespace std;

template <class T>
class PriorityQueue : public LinkedList<T> {
    public:
        PriorityQueue() = default;

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
        T dequeue() {
            if (empty())
                throw underflow_error("Error: cannot dequeue from empty queue.");
            return LinkedList<T>::remove_from_front();
        }
        T top() {
            return LinkedList<T>::get_item_at(0);
        }
        bool empty() {
            return (LinkedList<T>::length() == 0);
        }
        string to_string() {
            string s = "(";
            int i;
            for (i = 1; i < LinkedList<T>::length(); i++) {
                s += std::to_string(LinkedList<T>::get_item_at(i));
                s += ", ";
            }
            s += std::to_string(LinkedList<T>::get_item_at(i));
            s += ")";
            return s;
        }
};