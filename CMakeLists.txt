cmake_minimum_required(VERSION 3.24)
project(SDiZO)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(SOURCES src/models/DynamicArray.cpp src/models/DynamicArray.h src/models/DoublyLinkedList.cpp
        src/models/DoublyLinkedList.h src/models/RedBlackTree.cpp src/models/RedBlackTree.h
        src/models/BinarySearchTree.cpp src/models/BinarySearchTree.h src/models/BinaryMinHeap.cpp
        src/models/BinaryMinHeap.h src/views.h src/controllers.h)
set(TESTS test/DoublyLinedListTest.cpp test/DynamicArrayTest.cpp test/BinaryMinHeapTest.cpp
        test/BinarySearchTreeTest.cpp test/RedBlackTreeTest.cpp)

add_executable(SDiZO src/main.cpp ${SOURCES})
add_executable(tests libs/catch/catch_main.cpp ${SOURCES} ${TESTS})
