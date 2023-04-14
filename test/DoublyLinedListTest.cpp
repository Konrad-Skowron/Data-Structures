//
// Created by kosie on 14.03.2023.

#include <iostream>
#include <sstream>
#include "../libs/catch/catch.hpp"
#include "../src/DataStructures/DoublyLinkedList.h"

TEST_CASE("ListPushBack_1234") {
    std::ostringstream oss;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    auto *list = new DoublyLinkedList();

    list->pushBack(1);
    list->pushBack(2);
    list->pushBack(3);
    list->pushBack(4);

    list->printList();
    delete list;

    std::cout.rdbuf(sbuf);

    REQUIRE(oss.str() == "1 → 2 → 3 → 4 → 3 → 2 → 1\n");
}
