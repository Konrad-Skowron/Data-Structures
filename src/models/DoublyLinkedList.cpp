//
// Created by kosie on 13.03.2023.
//

#include <iostream>
#include "DoublyLinkedList.h"

Node::Node(int data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
}

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void DoublyLinkedList::pushBack(int data) {
    Node *newNode = new Node(data);
    if (size == 0) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void DoublyLinkedList::pushFront(int data) {
    Node *newNode = new Node(data);
    if (size == 0) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void DoublyLinkedList::popBack() {
    if (size == 0) {
        return;
    } else if (size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    size--;
}

void DoublyLinkedList::popFront() {
    if (size == 0) {
        return;
    } else if (size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
    size--;
}

void DoublyLinkedList::insert(int index, int data) {
    if (index < 0 || index > size) {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    Node *newNode = new Node(data);
    if (index == 0) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
    } else if (index == size) {
        newNode->prev = tail;
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = newNode;
        }
    } else {
        Node *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
    size++;
}

void DoublyLinkedList::remove(int index) {
    if (index < 0 || index >= size) {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    if (size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else if (index == 0) {
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    } else if (index == size - 1) {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    } else {
        Node *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
    size--;
}

Node *DoublyLinkedList::find(int data) {
    Node *current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void DoublyLinkedList::printList() {
    Node *current = head;
    while (current->next != nullptr) {
        std::cout << current->data << " → ";
        current = current->next;
    }
    std::cout << current->data <<std::endl;

    current = tail;
    while (current->prev != nullptr) {
        std::cout << current->data << " → ";
        current = current->prev;
    }
    std::cout << current->data << std::endl;
}

DoublyLinkedList::~DoublyLinkedList() {
    while (size > 0) {
        popFront();
    }
}
