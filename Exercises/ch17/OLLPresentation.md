# Ordered Linked Lists

By Luis, Adonis, Parker and Akshay

## Introduction

- An **ordered linked list** contains nodes pointing to each other in sequence
- However, these nodes are arranged in a specific order, unlinke in a standard linked list

## Functions

There is only one function that differentiates an ordered linked list and a normal linked list: the add-an-element function.

With normal linked lists, we just added an element at the start and made that the new head of the list. But with an ordered one, we'll have to insert the element in the perfect position so that the order is maintained.

The algorithm for doing this can be implemented in many ways, but we took inspiration from the logic detailed by GeeksForGeeks:

1) If the list is empty then make the node as head and return it.

2) If the value of the node to be inserted is smaller than the value of the head node, then insert the node at the start and make it head.

3) In a loop, find the appropriate node after which the input node is to be inserted. To find the appropriate node start from the head, keep moving until you reach a node who's value is greater than the input node. The node just before GN is the appropriate node.

4) Insert the node after the appropriate node found in step 3.

This is how each of us implemented that in code:

**Parker:**

```c++
void OrderedList::insert(int x) {

    Node* node = new Node(x);

    if (firstNode == nullptr) {
        firstNode = node;
        return;
    }

    Node* lastNode = nullptr;
    Node* nextNode = firstNode;

    while (nextNode) {
        if (nextNode->cargo > node->cargo) {
            lastNode = nextNode;
            nextNode = nextNode->next;
        }
        else {
            // nextNode->cargo <= x
            // so we insert
            node->next = nextNode;

            if (lastNode) {
                lastNode->next = node;
                return;
            }
            
            firstNode = node;
            return;
        }
    }

    lastNode->next = node;
}
```

**Luis:**

```c++
void insert_item(T carg){
    if (head == nullptr){
        insert_at_front(carg);
        return;
    } 

    Node<T>* current = head;
    Node<T>* previous = nullptr;

    while (current != nullptr && current->cargo < carg) {
        previous = current;
        current = current->next;
    }

    Node<T>* new_node = new Node<T>(carg, current);

    if (previous == nullptr) {
        head = new_node;
    } else {
        previous->next = new_node;
    }

    num_nodes++;
}
```

**Akshay:**

```c++
void addItem(T c) {
    this->numNodes++;
    Node<T>* n = new Node<T>(c);
    if (head == nullptr || head->getCargo() >= n->getCargo()) {
        n->setNext(head);
        head = n;
    } else {
        Node<T>* tracker = head;
        while (tracker->getNext() != nullptr && tracker->getNext()->getCargo() < n->getCargo()) {
            tracker = tracker->getNext();
        }
        n->setNext(tracker->getNext());
        tracker->setNext(n);
    }
}
```

## Inheritance

Although the `OrderedLinkedList` class can be created as its own class, entirely, it is also possible to make it a subclass of the original `LinkedList` class through public inheritance:

```c++
template <class T>
class OrderedLinkedList: public LinkedList<T> {
    ...
}
```

Doing so carries over the attributes from the `LinkedList` classs that are labeled `protected:`, as shown below:

```c++
class LinkedList { // Singly-linked list
    private:
        Node<T>* head; // The front of the list
    protected:
        int numNodes; // Number of nodes in the list
    ...
}
```

> ***Note:** in the code above, the member `numNodes` will be inherited by the `OrderedLinkedList` class from the `LinkedList` class.*

Protected members of the `LinkedList` class can be accessed by child classes as if it were their own native members. Private memebers, on the other hand, cannot be.

## Sources

- [Given a linked list which is sorted, how will you insert in sorted way](https://www.geeksforgeeks.org/given-a-linked-list-which-is-sorted-how-will-you-insert-in-sorted-way/)

- [C++ Inheritance Access](http://geeksforgeeks.org/cpp-inheritance-access/)
