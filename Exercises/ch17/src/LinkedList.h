#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H
#include <string>
#include <iostream>
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
        Node<T>* getHead() {
            return this->head;
        }
        // Default constructor
        LinkedList() {
            this->head = nullptr;
            this->numNodes = 0;
        }
        // Returns the number of nodes in the list
        int size() const {
            return this->numNodes;
        }
        // Adds a node to the beginning of the list
        // @param cargo: the data held by the new starting node
        void addFirst(T cargo) {
            Node<T>* n = new Node<T>(cargo, head);
            this->head = n;
            this->numNodes++;
        }
        // Removes the item at the front of the list and returns the data it contains
        T removeFront() {
            if (this->head == nullptr) {
                throw runtime_error("Error: cannot remove from an empty list.");
            }
            T frontCargo = head->getCargo();
            Node<T>* front = head;
            head = head->getNext();
            delete front;
            numNodes--;
            return frontCargo;
        }
        string to_string() const {
            if (head == nullptr) {
                return "Empty list";
            }
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
            if (head == nullptr) {
                string s = "Empty list";
                return s;
            }
            Node<T>* node = head;
            string s = ")";

            while (node != nullptr) {
                s = node->to_string() + s;
                node = node->getNext();
                if (node != nullptr)
                    s = ", " + s;
            }
            s = "(" + s;
            return s;
        }
};

#endif