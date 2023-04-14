//
// Created by kosie on 13.03.2023.
//

#ifndef SDIZO_DYNAMICARRAY_H
#define SDIZO_DYNAMICARRAY_H


class DynamicArray {
private:
    int *array;
    int size;
    int capacity;

    void grow();
    void shrink();

public:
    DynamicArray();
    explicit DynamicArray(int capacity);
    ~DynamicArray();
    void pushBack(int value);
    void pushFront(int value);
    void popBack();
    void popFront();
    void insert(int index, int value);
    void remove(int index);
    int find(int value);
    int getSize() const;
    void printArray();
};


#endif //SDIZO_DYNAMICARRAY_H
