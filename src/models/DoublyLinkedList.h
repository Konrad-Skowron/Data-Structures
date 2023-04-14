//
// Created by kosie on 13.03.2023.
//

#ifndef SDIZO_DOUBLYLINKEDLIST_H
#define SDIZO_DOUBLYLINKEDLIST_H


class Node {
public:
    int data;
    Node *next;
    Node *prev;

    explicit Node(int data);
};

class DoublyLinkedList {
private:
    Node *head;
    Node *tail;
    int size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void pushBack(int data);
    void pushFront(int data);
    void popBack();
    void popFront();
    void insert(int index, int data);
    void remove(int index);
    Node *find(int data);
    void printList();
};


#endif //SDIZO_DOUBLYLINKEDLIST_H
