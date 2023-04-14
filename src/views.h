//
// Created by kosie on 12.04.2023.
//

#ifndef SDIZO_VIEWS_H
#define SDIZO_VIEWS_H

#include <iostream>
#include "controllers.h"

void menuDS();

void menuArr() {
    std::cout << "1. Insert" << std::endl;
    std::cout << "2. Remove" << std::endl;
    std::cout << "3. Search" << std::endl;
    int choice, value;
    std::cin >> choice;
    switch (choice) {
        case 1:
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            std::cout << "1. Insert at beginning" << std::endl;
            std::cout << "2. Insert at end" << std::endl;
            std::cout << "3. Insert at index" << std::endl;
            std::cin >> choice;
            switch (choice) {
                case 1:
                    startTime = Clock::now();
                    arr->pushFront(value);
                    break;
                case 2:
                    startTime = Clock::now();
                    arr->pushBack(value);
                    break;
                case 3:
                    std::cout << "Enter index: ";
                    int index;
                    std::cin >> index;
                    startTime = Clock::now();
                    arr->insert(index, value);
                    break;
                default:
                    return;
            }
            endTime = Clock::now();
            arr->printArray();
            getTime(startTime, endTime);
            menuDS();
            break;
        case 2:
            std::cout << "1. Delete at beginning" << std::endl;
            std::cout << "2. Delete at end" << std::endl;
            std::cout << "3. Delete at index" << std::endl;
            std::cin >> choice;
            switch (choice) {
                case 1:
                    startTime = Clock::now();
                    arr->popFront();
                    break;
                case 2:
                    startTime = Clock::now();
                    arr->popBack();
                    break;
                case 3:
                    std::cout << "Enter index: ";
                    int index;
                    std::cin >> index;
                    startTime = Clock::now();
                    arr->remove(index);
                    break;
                default:
                    return;
            }
            endTime = Clock::now();
            arr->printArray();
            getTime(startTime, endTime);
            menuDS();
            break;
        case 3:
            std::cout << "Enter value to find: ";
            std::cin >> value;
            startTime = Clock::now();
            std::cout << arr->find(value) << std::endl;
            endTime = Clock::now();
            getTime(startTime, endTime);
            menuDS();
            break;
        default:
            return;
    }
}

void menuList() {
    std::cout << "1. Insert" << std::endl;
    std::cout << "2. Delete" << std::endl;
    std::cout << "3. Search" << std::endl;
    int choice, value;
    std::cin >> choice;
    switch (choice) {
        case 1:
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            std::cout << "1. Insert at beginning" << std::endl;
            std::cout << "2. Insert at end" << std::endl;
            std::cout << "3. Insert at index" << std::endl;
            std::cin >> choice;
            switch (choice) {
                case 1:
                    startTime = Clock::now();
                    list->pushFront(value);
                    break;
                case 2:
                    startTime = Clock::now();
                    list->pushBack(value);
                    break;
                case 3:
                    std::cout << "Enter index: ";
                    int index;
                    std::cin >> index;
                    startTime = Clock::now();
                    list->insert(index, value);
                    break;
                default:
                    return;
            }
            endTime = Clock::now();
            list->printList();
            getTime(startTime, endTime);
            menuDS();
            break;
        case 2:
            std::cout << "1. Delete at beginning" << std::endl;
            std::cout << "2. Delete at end" << std::endl;
            std::cout << "3. Delete at index" << std::endl;
            std::cin >> choice;
            switch (choice) {
                case 1:
                    startTime = Clock::now();
                    list->popFront();
                    break;
                case 2:
                    startTime = Clock::now();
                    list->popBack();
                    break;
                case 3:
                    std::cout << "Enter index: ";
                    int index;
                    std::cin >> index;
                    startTime = Clock::now();
                    list->remove(index);
                    break;
                default:
                    return;
            }
            endTime = Clock::now();
            list->printList();
            getTime(startTime, endTime);
            menuDS();
            break;
        case 3:
            std::cout << "Enter value to find: ";
            std::cin >> value;
            startTime = Clock::now();
            std::cout << list->find(value) << std::endl;
            endTime = Clock::now();
            getTime(startTime, endTime);
            menuDS();
            break;
        default:
            return;
    }
}

void menuHeap() {
    std::cout << "1. Insert" << std::endl;
    std::cout << "2. Delete min" << std::endl;
    std::cout << "3. Search" << std::endl;
    int choice, value;
    std::cin >> choice;
    switch (choice) {
        case 1:
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            startTime = Clock::now();
            heap->insert(value);
            endTime = Clock::now();
            heap->printHeap();
            getTime(startTime, endTime);
            menuDS();
            break;
        case 2:
            startTime = Clock::now();
            heap->deleteMin();
            endTime = Clock::now();
            heap->printHeap();
            getTime(startTime, endTime);
            menuDS();
            break;
        case 3:
            std::cout << "Enter value to find: ";
            std::cin >> value;
            startTime = Clock::now();
            std::cout << heap->find(value) << std::endl;
            endTime = Clock::now();
            getTime(startTime, endTime);
            menuDS();
            break;
        default:
            return;
    }
}

void menuBST() {
    std::cout << "1. Insert" << std::endl;
    std::cout << "2. Delete" << std::endl;
    std::cout << "3. Search" << std::endl;
    std::cout << "4. Balance" << std::endl;
    int choice, value;
    std::cin >> choice;
    switch (choice) {
        case 1:
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            startTime = Clock::now();
            bst->insertNode(value);
            endTime = Clock::now();
            bst->printBST();
            getTime(startTime, endTime);
            menuDS();
        case 2:
            std::cout << "Enter value to delete: ";
            std::cin >> value;
            startTime = Clock::now();
            bst->deleteNode(value);
            endTime = Clock::now();
            bst->printBST();
            getTime(startTime, endTime);
            menuDS();
            break;
        case 3:
            std::cout << "Enter value to find: ";
            std::cin >> value;
            startTime = Clock::now();
            std::cout << bst->find(value) << std::endl;
            endTime = Clock::now();
            getTime(startTime, endTime);
            menuDS();
            break;
        case 4:
            startTime = Clock::now();
            bst->createBalancedTree();
            endTime = Clock::now();
            bst->printBST();
            getTime(startTime, endTime);
            menuDS();
            break;
        default:
            return;
    }
}

void menuRBT() {
    std::cout << "1. Insert" << std::endl;
    std::cout << "2. Delete" << std::endl;
    std::cout << "3. Search" << std::endl;
    int choice, value;
    std::cin >> choice;
    switch (choice) {
        case 1:
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            startTime = Clock::now();
            rbt->insertNode(value);
            endTime = Clock::now();
            rbt->printRBT();
            getTime(startTime, endTime);
            menuDS();
            break;
        case 2:
            std::cout << "Enter value to delete: ";
            std::cin >> value;
            startTime = Clock::now();
            rbt->deleteNode(rbt->find(value));
            endTime = Clock::now();
            rbt->printRBT();
            getTime(startTime, endTime);
            menuDS();
            break;
        case 3:
            std::cout << "Enter value to find: ";
            std::cin >> value;
            startTime = Clock::now();
            std::cout << rbt->find(value) << std::endl;
            endTime = Clock::now();
            getTime(startTime, endTime);
            menuDS();
            break;
        default:
            return;
    }
}

void menuDS() {
    std::cout << "1. Dynamic Array" << std::endl;
    std::cout << "2. Doubly Linked List" << std::endl;
    std::cout << "3. Binary Min Heap" << std::endl;
    std::cout << "4. Binary Search Tree" << std::endl;
    std::cout << "5. Red Black Tree" << std::endl;
    std::cout << "6. Exit" << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            arr->printArray();
            menuArr();
            break;
        case 2:
            list->printList();
            menuList();
            break;
        case 3:
            heap->printHeap();
            menuHeap();
            break;
        case 4:
            bst->printBST();
            menuBST();
            break;
        case 5:
            rbt->printRBT();
            menuRBT();
            break;
        case 6:
            return;
        default:
            return;
    }
}

void menuMain() {
    std::cout << "1. Load values from file" << std::endl;
    std::cout << "2. Load random values" << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            readFromFile();
            menuDS();
            break;
        case 2:
            std::cout << "Size: ";
            int num;
            std::cin >> num;
            appendRandomData(num);
            menuDS();
            break;
        default:
            return;
    }
}

#endif //SDIZO_VIEWS_H
