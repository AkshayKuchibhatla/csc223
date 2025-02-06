#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H
#include <string>
using namespace std;

template <class T>
class Node {
    T cargo;
    Node<T>* next;

    public:
        Node() {}
        Node(T cargo) {
            this->cargo = cargo;
            this->next = nullptr;
        }
        // Creates a new node
        // @param cargo: the data held by the new node
        // @param nextNode: the address of the next node
        Node(T cargo, Node<T>* nextNode) {
            this->cargo = cargo;
            this->next = nextNode;
        }
        T getCargo() {
            return cargo;
        }
        Node<T>* getNext() {
            return next;
        }
        string to_string() const {
            return std::to_string(cargo);
        }
};

template <class T>
class LinkedList {
    int numNodes; // Number of nodes in the list
    Node<T>* head; // The front of the list
    public:
        // Default constructor
        LinkedList() {
            head = nullptr;
            numNodes = 0;
        }
        // Returns if the list is empty or not
        bool empty() {
            return (head == nullptr);
        }
        // Returns the number of nodes in the list
        int size() const {
            return numNodes;
        }
        // Adds a node to the beginning of the list
        // @param cargo: the data held by the new starting node
        void addFirst(T cargo) {
            Node<T>* n = new Node<T>(cargo, head);
            head = n;
            numNodes++;
        }
        // Removes the item at the front of the list and returns the data it contains
        T removeFront() {
            if (empty()) {
                throw runtime_error("Error: cannot remove from an empty list.");
            }
            T frontCargo = head->cargo;
            Node<T> front = head;
            head = head->getNext();
            delete front;
            numNodes--;
            return frontCargo;
        }
        string to_string() const {
            Node<T>* node = head;
            string s = "(";

            while (node != nullptr) {
                s += node->to_string();
                node = node->getNext();
                if (node != nullptr)
                    s += ", ";
            }
            s += ")";
            return s;
        }
        string to_string_reverse() const {
            Node<T>* node = head;
            string s = ")";

            while (node != nullptr) {
                s = Node<T>::to_string(node) + s;
                node = node->getNext();
                if (node != nullptr)
                    s = ", " + s;
            }
            s += ")";
            return s;
        }
};

#endif