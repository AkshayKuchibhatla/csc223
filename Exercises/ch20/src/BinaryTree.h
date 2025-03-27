#include <iostream>
using namespace std;

template <class T>
struct Node {
    T cargo;
    Node<T>* left;
    Node<T>* right;

    Node(T cargo) {
        this->cargo = cargo;
        this->left = nullptr;
        this-right = nullptr;
    }

    Node(T cargo, Node<T>* left, Node<T>* right) {
        this->cargo = cargo;
        this->left = left;
        this-right = right;
    }
};