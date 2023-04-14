//
// Created by kosie on 13.03.2023.
//

#ifndef SDIZO_REDBLACKTREE_H
#define SDIZO_REDBLACKTREE_H

#include <string>

enum Color {
    RED, BLACK
};

class RBTNode {
public:
    int data;
    RBTNode *left;
    RBTNode *right;
    RBTNode *parent;
    Color color;
};

class RedBlackTree {
private:
    RBTNode S;
    RBTNode *root;
    void deleteTree(RBTNode *node);
public:
    RedBlackTree();
    ~RedBlackTree();
    void printRBT(const std::string &prefix, const RBTNode *node, bool isLeft);
    void printRBT();
    RBTNode *find(int k);
    RBTNode *minRBT(RBTNode *p);
    RBTNode *succRBT(RBTNode *p);
    void rot_L(RBTNode *A);
    void rot_R(RBTNode *A);
    void insertNode(int k);
    void deleteNode(RBTNode *node);
};


#endif //SDIZO_REDBLACKTREE_H
