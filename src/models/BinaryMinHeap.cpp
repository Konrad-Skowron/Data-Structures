//
// Created by kosie on 13.03.2023.
//

#include <iostream>
#include <cmath>
#include "BinaryMinHeap.h"

int BinaryMinHeap::parent(int index) {
    return (index - 1) / 2;
}

int BinaryMinHeap::leftChild(int index) {
    return 2 * index + 1;
}

int BinaryMinHeap::rightChild(int index) {
    return 2 * index + 2;
}

void BinaryMinHeap::heapFixUp(int index) {
    while (index > 0 && heap[parent(index)] > heap[index]) {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void BinaryMinHeap::heapFixDown(int index) {
    int minIndex = index;
    int l = leftChild(index);
    if (l < size && heap[l] < heap[minIndex]) {
        minIndex = l;
    }
    int r = rightChild(index);
    if (r < size && heap[r] < heap[minIndex]) {
        minIndex = r;
    }
    if (index != minIndex) {
        std::swap(heap[index], heap[minIndex]);
        heapFixDown(minIndex);
    }
}

BinaryMinHeap::BinaryMinHeap() {
    this->capacity = 1;
    heap = new int[capacity];
    size = 0;
}

BinaryMinHeap::BinaryMinHeap(int capacity) {
    this->capacity = capacity;
    heap = new int[capacity];
    size = 0;
}

BinaryMinHeap::~BinaryMinHeap() {
    delete[] heap;
}

void BinaryMinHeap::deleteMin() {
    if (size == 0) {
        return;
    }
    heap[0] = heap[size - 1];
    size--;
    heapFixDown(0);
}

void BinaryMinHeap::insert(int value) {
    if (size == capacity) {
        // resize heap if necessary
        int* newHeap = new int[2 * capacity];
        for (int i = 0; i < capacity; i++) {
            newHeap[i] = heap[i];
        }
        delete[] heap;
        heap = newHeap;
        capacity *= 2;
    }
    heap[size] = value;
    size++;
    heapFixUp(size - 1);
}

int BinaryMinHeap::find(int value) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == value) {
            return i;
        }
    }
    return -1;
}

void BinaryMinHeap::printHeap() {
    printHeap("", 0, false);
}

void BinaryMinHeap::printHeap(const std::string& prefix, const int index, bool isLeft) {
    if (index < size) {
        std::cout << prefix;

        if (index == 0) {
            // print the data of the node
            std::cout << heap[index] << std::endl;

            // enter the next tree level - left and right branch
            printHeap(prefix + (isLeft ? "│" : ""), leftChild(index), true);
            printHeap(prefix + (isLeft ? "│" : ""), rightChild(index), false);
        } else {
            std::cout << (isLeft ? "├── " : "└── ") << heap[index] << std::endl;

            printHeap(prefix + (isLeft ? "│   " : "    "), leftChild(index), true);
            printHeap(prefix + (isLeft ? "│   " : "    "), rightChild(index), false);
        }
    }
}
