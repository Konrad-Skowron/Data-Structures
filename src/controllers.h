//
// Created by kosie on 12.04.2023.
//

#ifndef SDIZO_CONTROLLERS_H
#define SDIZO_CONTROLLERS_H

#include <iostream>
#include <chrono>
#include <fstream>
#include <random>
#include <algorithm>
#include <iomanip>
#include "models/DynamicArray.h"
#include "models/DoublyLinkedList.h"
#include "models/BinaryMinHeap.h"
#include "models/BinarySearchTree.h"
#include "models/RedBlackTree.h"
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::time_point<std::chrono::high_resolution_clock> TimePoint;

DynamicArray *arr;
DoublyLinkedList *list;
BinaryMinHeap *heap;
BinarySearchTree *bst;
RedBlackTree *rbt;
TimePoint startTime, endTime;

long long getTime(TimePoint &start, TimePoint &end) {
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    // std::cout << "Time [ns]: " << duration << std::endl;
    return duration;
}

void dsInit() {
    arr = new DynamicArray();
    list = new DoublyLinkedList();
    heap = new BinaryMinHeap();
    bst = new BinarySearchTree();
    rbt = new RedBlackTree();
}

void dsDelete() {
    delete arr;
    delete list;
    delete heap;
    delete bst;
    delete rbt;
}

void appendData(char dataStructure, int data) {
    switch (int(dataStructure) - '0') {
        case 1:
            arr->pushBack(data);
            break;
        case 2:
            list->pushBack(data);
            break;
        case 3:
            heap->insert(data);
            break;
        case 4:
            bst->insertNode(data);
            break;
        case 5:
            rbt->insertNode(data);
            break;
    }
}

void appendRandomData(int size) {
    int values[size];
    for (int i = 0; i < size; i++) {
        values[i] = i;
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(values, values + size, g);

    for (int n : values) {
        arr->pushBack(n);
        list->pushBack(n);
        heap->insert(n);
        bst->insertNode(n);
        rbt->insertNode(n);
    }
}

void readFromFile() {
    std::ifstream file("../input.txt");
    std::string line;

    if (!file.is_open()) {
        std::cout << "Failed to open file." << std::endl;
        return;
    }

    while (getline(file, line)) {
        std::string num;
        for (int i = 1; i < line.length(); i++) {
            if (line[i] >= 48 && line[i] <= 57) {
                num += line[i];
            } else if (!num.empty()) {
                appendData(line[0], std::stoi(num));
                num = "";
            }
        }
        if (!num.empty()) {
            appendData(line[0], std::stoi(num));
        }
    }
    file.close();
}

void testTime() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator

    int sizes[5] = {1000, 5000, 10000, 25000, 50000};
    long long arrTime[7] = {0}, listTime[7] = {0}, heapTime[7] = {0}, bstTime[7] = {0}, rbtTime[7] = {0};

    for (int size : sizes) {
        std::uniform_int_distribution<> distrExisting(0, size - 1);
        std::uniform_int_distribution<> distrNew(size + 1, 2 * size);
        std::cout << "Size: " << size << std::endl;

        for (int i = 0; i < 100; i++) {
            dsInit();

            appendRandomData(size);

            startTime = Clock::now();
            arr->find(distrExisting(gen));
            endTime = Clock::now();
            arrTime[0] += getTime(startTime, endTime);

            startTime = Clock::now();
            arr->pushBack(distrNew(gen));
            endTime = Clock::now();
            arrTime[1] += getTime(startTime, endTime);

            startTime = Clock::now();
            arr->pushFront(distrNew(gen));
            endTime = Clock::now();
            arrTime[2] += getTime(startTime, endTime);

            startTime = Clock::now();
            arr->insert(distrExisting(gen), distrNew(gen));
            endTime = Clock::now();
            arrTime[3] += getTime(startTime, endTime);

            startTime = Clock::now();
            arr->remove(distrExisting(gen));
            endTime = Clock::now();
            arrTime[4] += getTime(startTime, endTime);

            startTime = Clock::now();
            arr->popBack();
            endTime = Clock::now();
            arrTime[5] += getTime(startTime, endTime);

            startTime = Clock::now();
            arr->popFront();
            endTime = Clock::now();
            arrTime[6] += getTime(startTime, endTime);


            startTime = Clock::now();
            list->find(distrExisting(gen));
            endTime = Clock::now();
            listTime[0] += getTime(startTime, endTime);

            startTime = Clock::now();
            list->pushBack(distrNew(gen));
            endTime = Clock::now();
            listTime[1] += getTime(startTime, endTime);

            startTime = Clock::now();
            list->pushFront(distrNew(gen));
            endTime = Clock::now();
            listTime[2] += getTime(startTime, endTime);

            startTime = Clock::now();
            list->insert(distrExisting(gen), distrNew(gen));
            endTime = Clock::now();
            listTime[3] += getTime(startTime, endTime);

            startTime = Clock::now();
            list->remove(distrExisting(gen));
            endTime = Clock::now();
            listTime[4] += getTime(startTime, endTime);

            startTime = Clock::now();
            list->popBack();
            endTime = Clock::now();
            listTime[5] += getTime(startTime, endTime);

            startTime = Clock::now();
            list->popFront();
            endTime = Clock::now();
            listTime[6] += getTime(startTime, endTime);


            startTime = Clock::now();
            heap->find(distrExisting(gen));
            endTime = Clock::now();
            heapTime[0] += getTime(startTime, endTime);

            startTime = Clock::now();
            heap->insert(distrNew(gen));
            endTime = Clock::now();
            heapTime[1] += getTime(startTime, endTime);

            startTime = Clock::now();
            heap->deleteMin();
            endTime = Clock::now();
            heapTime[2] += getTime(startTime, endTime);


            startTime = Clock::now();
            bst->find(distrExisting(gen));
            endTime = Clock::now();
            bstTime[0] += getTime(startTime, endTime);

            startTime = Clock::now();
            bst->insertNode(distrNew(gen));
            endTime = Clock::now();
            bstTime[1] += getTime(startTime, endTime);

            startTime = Clock::now();
            bst->createBalancedTree();
            endTime = Clock::now();
            bstTime[3] += getTime(startTime, endTime);

            startTime = Clock::now();
            bst->deleteNode(distrExisting(gen));
            endTime = Clock::now();
            bstTime[2] += getTime(startTime, endTime);


            startTime = Clock::now();
            rbt->find(distrExisting(gen));
            endTime = Clock::now();
            rbtTime[0] += getTime(startTime, endTime);

            startTime = Clock::now();
            rbt->insertNode(distrNew(gen));
            endTime = Clock::now();
            rbtTime[1] += getTime(startTime, endTime);

            startTime = Clock::now();
            rbt->deleteNode(rbt->find(distrExisting(gen)));
            endTime = Clock::now();
            rbtTime[2] += getTime(startTime, endTime);

            dsDelete();
        }
        for (int i = 0; i < 7; i++) {
            arrTime[i] /= 100;
            listTime[i] /= 100;
            heapTime[i] /= 100;
            bstTime[i] /= 100;
            rbtTime[i] /= 100;
            std::cout << std::setw(8) << arrTime[i];
            std::cout << std::setw(8) << listTime[i];
            std::cout << std::setw(8) << heapTime[i];
            std::cout << std::setw(8) << bstTime[i];
            std::cout << std::setw(8) << rbtTime[i];
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

#endif //SDIZO_CONTROLLERS_H
