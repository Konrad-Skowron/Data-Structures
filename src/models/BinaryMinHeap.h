//
// Created by kosie on 13.03.2023.
//

#ifndef SDIZO_BINARYMINHEAP_H
#define SDIZO_BINARYMINHEAP_H


class BinaryMinHeap {
private:
    int *heap;
    int size;
    int capacity;

    static int parent(int index);
    static int leftChild(int index);
    static int rightChild(int index);
    void heapFixUp(int index);
    void heapFixDown(int index);
    void printHeap(const std::string& prefix, int index, bool isLeft);
public:
    BinaryMinHeap();
    explicit BinaryMinHeap(int capacity);
    ~BinaryMinHeap();
    void insert(int value);
    void deleteMin();
    int find(int value);
    void printHeap();
};


#endif //SDIZO_BINARYMINHEAP_H
