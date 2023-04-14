//
// Created by kosie on 13.03.2023.
//

#include <iostream>
#include "DynamicArray.h"

DynamicArray::DynamicArray() {
    size = 0;
    capacity = 1;
    array = new int[capacity];
}

DynamicArray::DynamicArray(int capacity) {
    this->capacity = capacity;
    size = 0;
    array = new int[capacity];
}

void DynamicArray::grow() {
    capacity *= 2;
    int *temp = new int[capacity];
    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}

void DynamicArray::shrink() {
    capacity = size;
    int *temp = new int[capacity];
    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}

void DynamicArray::pushBack(int value) {
    if (size == capacity) {
        grow();
    }
    array[size] = value;
    size++;
}

void DynamicArray::pushFront(int value) {
    if (size == capacity) {
        grow();
    }
    for (int i = size; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = value;
    size++;
}

void DynamicArray::popBack() {
    array[size - 1] = 0;
    size--;
    if (size == (capacity / 2)) {
        shrink();
    }
}

void DynamicArray::popFront() {
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    array[size - 1] = 0;
    size--;
    if (size == (capacity / 2)) {
        shrink();
    }
}

void DynamicArray::insert(int index, int value) {
    if (index < 0 || index > size) {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    if (size == capacity) {
        grow();
    }
    for (int i = size; i > index; i--) {
        array[i] = array[i - 1];
    }
    array[index] = value;
    size++;
}

void DynamicArray::remove(int index) {
    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    array[size - 1] = 0;
    size--;
    if (size == (capacity / 2)) {
        shrink();
    }
}

int DynamicArray::find(int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

int DynamicArray::getSize() const {
    return size;
}

void DynamicArray::printArray() {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

DynamicArray::~DynamicArray() {
    delete[] array;
}

