//
// Created by kosie on 20.03.2023.
//

#ifndef SDIZO_BINARYSEARCHTREE_H
#define SDIZO_BINARYSEARCHTREE_H

class BSTNode {
public:
    int data;
    BSTNode *left;
    BSTNode *right;
    BSTNode *parent;
    explicit BSTNode(int data);
};

class BinarySearchTree {
private:
    BSTNode *root;
    int nodeCount;
    BSTNode *find(BSTNode *node, int data);
    void leftRotate(BSTNode *node);
    void rightRotate(BSTNode *node);
    void deleteTree(BSTNode *node);
    BSTNode *deleteNode(BSTNode* node, int data);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    BSTNode *find(int data);
    void insertNode(int data);
    void deleteNode(int data);
    void createLinearTree();
    void createBalancedTree();
    void printBST(const std::string &prefix, const BSTNode *node, bool isLeft);
    void printBST();
};


#endif //SDIZO_BINARYSEARCHTREE_H
