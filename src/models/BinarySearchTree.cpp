//
// Created by kosie on 20.03.2023.
//

#include <cmath>
#include <iostream>
#include "BinarySearchTree.h"

BSTNode::BSTNode(int data) {
    this->data = data;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
    nodeCount = 0;
}

BSTNode *BinarySearchTree::find(BSTNode *node, int data) {
    if (node == nullptr || node->data == data) {
        return node;
    }
    if (data < node->data) {
        return find(node->left, data);
    } else {
        return find(node->right, data);
    }
}

BSTNode *BinarySearchTree::find(int data) {
    BSTNode *node = find(root, data);
    if (node == nullptr) {
        std::cout << "Node not found" << std::endl;
    }
    return node;
}

void BinarySearchTree::insertNode(int data) {
    auto *newNode = new BSTNode(data);

    BSTNode *parent = nullptr;
    BSTNode *current = root;
    while (current != nullptr) {
        parent = current;
        if (newNode->data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;
    if (parent == nullptr) {
        root = newNode;
    } else if (newNode->data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    nodeCount++;
}

void BinarySearchTree::deleteNode(int data) {
    deleteNode(root, data);
}

BSTNode *BinarySearchTree::deleteNode(BSTNode* node, int data) {
    if (node == nullptr) {
        return node;
    }
    if (node->data > data) {
        node->left = deleteNode(node->left, data);
    } else if (node->data < data) {
        node->right = deleteNode(node->right, data);
    } else {
        if (node->left == nullptr) {
            BSTNode *temp = node->right;
            free (node);
            return temp;
        } else if (node->right == nullptr) {
            BSTNode *temp = node->left;
            free (node);
            return temp;
        } else {
            BSTNode *temp = node->right;

            while (temp->left != nullptr)
                temp = temp->left;

            node->data = temp->data;

            node->right = deleteNode(node->right, temp->data);
        }
    }
    nodeCount--;
    return node;
}

void BinarySearchTree::leftRotate(BSTNode *node) {
    BSTNode *temp = node->right;
    node->right = temp->left;
    if (temp->left != nullptr) {
        temp->left->parent = node;
    }
    temp->parent = node->parent;
    if (node->parent == nullptr) {
        root = temp;
    } else if (node == node->parent->left) {
        node->parent->left = temp;
    } else {
        node->parent->right = temp;
    }
    temp->left = node;
    node->parent = temp;
}

void BinarySearchTree::rightRotate(BSTNode *node) {
    BSTNode *temp = node->left;
    node->left = temp->right;
    if (temp->right != nullptr) {
        temp->right->parent = node;
    }
    temp->parent = node->parent;
    if (node->parent == nullptr) {
        root = temp;
    } else if (node == node->parent->right) {
        node->parent->right = temp;
    } else {
        node->parent->left = temp;
    }
    temp->right = node;
    node->parent = temp;
}

void BinarySearchTree::createLinearTree() {
    BSTNode *temp = root;
    while (temp != nullptr) {
        if (temp->left != nullptr) {
            rightRotate(temp);
            temp = temp->parent;
        } else {
            temp = temp->right;
        }
    }
}

void BinarySearchTree::createBalancedTree() {
    createLinearTree();
    int edgeCount = pow(2, floor(log2(nodeCount + 1))) - 1;
    BSTNode *temp = root;
    for (int i = 0; i < nodeCount - edgeCount; i++) {
        leftRotate(temp);
        temp = temp->parent->right;
    }
    while (edgeCount > 1) {
        edgeCount = floor(edgeCount / 2);
        temp = root;
        for (int i = 0; i < edgeCount; i++) {
            leftRotate(temp);
            temp = temp->parent->right;
        }
    }
}

void BinarySearchTree::printBST(const std::string& prefix, const BSTNode *node, bool isLeft) {
    if (node != nullptr) {
        std::cout << prefix;

        if (node == root) {
            // print the data of the node
            std::cout << node->data << std::endl;

            // enter the next tree level - left and right branch
            printBST(prefix + (isLeft ? "│" : ""), node->left, true);
            printBST(prefix + (isLeft ? "│" : ""), node->right, false);
        } else {
            std::cout << (isLeft ? "├── " : "└── ") << node->data << std::endl;

            printBST(prefix + (isLeft ? "│   " : "    "), node->left, true);
            printBST(prefix + (isLeft ? "│   " : "    "), node->right, false);
        }
    }
}

void BinarySearchTree::printBST() {
    printBST("", root, false);
}

BinarySearchTree::~BinarySearchTree() {
    deleteTree(root);
}

void BinarySearchTree::deleteTree(BSTNode *node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}
