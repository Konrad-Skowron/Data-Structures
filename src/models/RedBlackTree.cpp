//
// Created by kosie on 13.03.2023.
//

#include "RedBlackTree.h"

#include <iostream>

RedBlackTree::RedBlackTree() {
    S.color = Color::BLACK;
    S.parent = &S;
    S.left = &S;
    S.right = &S;
    root = &S;
}

RBTNode * RedBlackTree::find(int k)
{
    RBTNode * p;

    p = root;
    while ((p != &S) && (p->data != k))
        if (k < p->data) p = p->left;
        else           p = p->right;
    if (p == &S) return nullptr;
    return p;
}

// Wyszukuje najmniejszy węzeł w poddrzewie
// o korzeniu p
//-----------------------------------------
RBTNode * RedBlackTree::minRBT(RBTNode * p) {
    if (p != &S)
        while (p->left != &S) p = p->left;
    return p;
}

// Zwraca następnik p
//-------------------
RBTNode * RedBlackTree::succRBT(RBTNode * p) {
    RBTNode * r;

    if (p != &S) {
        if (p->right != &S) return minRBT(p->right);
        else {
            r = p->parent;
            while ((r != &S) && (p == r->right)) {
                p = r;
                r = r->parent;
            }
            return r;
        }
    }
    return &S;
}

// Wykonuje rotację w lewo względem A
//-----------------------------------
void RedBlackTree::rot_L(RBTNode * A) {
    RBTNode * B, * p;

    B = A->right;
    if (B != &S) {
        p = A->parent;
        A->right = B->left;
        if (A->right != &S) A->right->parent = A;

        B->left = A;
        B->parent = p;
        A->parent = B;

        if (p != &S) {
            if (p->left == A) p->left = B; else p->right = B;
        }
        else root = B;
    }
}

// Wykonuje rotację w prawo względem A
//------------------------------------
void RedBlackTree::rot_R(RBTNode * A) {
    RBTNode * B, * p;

    B = A->left;
    if (B != &S) {
        p = A->parent;
        A->left = B->right;
        if (A->left != &S) A->left->parent = A;

        B->right = A;
        B->parent = p;
        A->parent = B;

        if (p != &S) {
            if (p->left == A) p->left = B;
            else p->right = B;
        }
        else root = B;
    }
}

// Wstawia do drzewa węzeł o kluczu k
//-----------------------------------
void RedBlackTree::insertNode(int k) {
    RBTNode * X, * Y;

    X = new RBTNode;        // Tworzymy nowy węzeł
    X->left  = &S;          // Inicjujemy pola
    X->right = &S;
    X->parent = root;
    X->data = k;
    if (X->parent == &S) root = X; // X staje się korzeniem
    else
        while (true) {          // Szukamy liścia do zastąpienia przez X
            if (k < X->parent->data) {
                if (X->parent->left == &S) {
                    X->parent->left = X;  // X zastępuje lewy liść
                    break;
                }
                X->parent = X->parent->left;
            } else {
                if (X->parent->right == &S) {
                    X->parent->right = X; // X zastępuje prawy liść
                    break;
                }
                X->parent = X->parent->right;
            }
        }
    X->color = Color::RED;         // Węzeł kolorujemy na czerwono
    while ((X != root) && (X->parent->color == Color::RED)) {
        if (X->parent == X->parent->parent->left) {
            Y = X->parent->parent->right; // Y -> wujek X

            if (Y->color == Color::RED) { // Przypadek 1
                X->parent->color = Color::BLACK;
                Y->color = Color::BLACK;
                X->parent->parent->color = Color::RED;
                X = X->parent->parent;
                continue;
            }

            if (X == X->parent->right) { // Przypadek 2
                X = X->parent;
                rot_L (X);
            }

            X->parent->color = Color::BLACK; // Przypadek 3
            X->parent->parent->color = Color::RED;
            rot_R(X->parent->parent);
            break;
        }
        else {                  // Przypadki lustrzane
            Y = X->parent->parent->left;

            if (Y->color == Color::RED) { // Przypadek 1
                X->parent->color = Color::BLACK;
                Y->color = Color::BLACK;
                X->parent->parent->color = Color::RED;
                X = X->parent->parent;
                continue;
            }

            if (X == X->parent->left) { // Przypadek 2
                X = X->parent;
                rot_R(X);
            }

            X->parent->color = Color::BLACK; // Przypadek 3
            X->parent->parent->color = Color::RED;
            rot_L(X->parent->parent);
            break;
        }
    }
    root->color = Color::BLACK;
}

// Usuwa z drzewa węzeł X
//-----------------------
void RedBlackTree::deleteNode(RBTNode *X) {
    RBTNode *W, *Y, *Z;

    if ((X->left == &S) || (X->right == &S)) Y = X;
    else Y = succRBT (X);

    if (Y->left != &S) Z = Y->left;
    else Z = Y->right;

    Z->parent = Y->parent;

    if (Y->parent == &S) root = Z;
    else if (Y == Y->parent->left) Y->parent->left  = Z;
    else Y->parent->right = Z;

    if (Y != X) X->data = Y->data;

    if (Y->color == Color::BLACK)   // Naprawa struktury drzewa czerwono-czarnego
        while ((Z != root) && (Z->color == Color::BLACK))
            if (Z == Z->parent->left) {
                W = Z->parent->right;

                if (W->color == Color::RED) {              // Przypadek 1
                    W->color = Color::BLACK;
                    Z->parent->color = Color::RED;
                    rot_L (Z->parent);
                    W = Z->parent->right;
                }

                if ((W->left->color == Color::BLACK) && (W->right->color == Color::BLACK)) {              // Przypadek 2
                    W->color = Color::RED;
                    Z = Z->parent;
                    continue;
                }

                if (W->right->color == Color::BLACK) {              // Przypadek 3
                    W->left->color = Color::BLACK;
                    W->color = Color::RED;
                    rot_R (W);
                    W = Z->parent->right;
                }

                W->color = Z->parent->color; // Przypadek 4
                Z->parent->color = Color::BLACK;
                W->right->color = Color::BLACK;
                rot_L (Z->parent);
                Z = root;      // To spowoduje zakończenie pętli
            }
            else {                // Przypadki lustrzane
                W = Z->parent->left;

                if (W->color == Color::RED) {              // Przypadek 1
                    W->color = Color::BLACK;
                    Z->parent->color = Color::RED;
                    rot_R (Z->parent);
                    W = Z->parent->left;
                }

                if ((W->left->color == Color::BLACK) && (W->right->color == Color::BLACK)) {              // Przypadek 2
                    W->color = Color::RED;
                    Z = Z->parent;
                    continue;
                }

                if (W->left->color == Color::BLACK) {              // Przypadek 3
                    W->right->color = Color::BLACK;
                    W->color = Color::RED;
                    rot_L (W);
                    W = Z->parent->left;
                }

                W->color = Z->parent->color;  // Przypadek 4
                Z->parent->color = Color::BLACK;
                W->left->color = Color::BLACK;
                rot_R(Z->parent);
                Z = root;      // To spowoduje zakończenie pętli
            }

    Z->color = Color::BLACK;

    delete Y;
}

void RedBlackTree::printRBT(const std::string& prefix, const RBTNode *node, bool isLeft) {
    if (node != &S) {
        std::cout << prefix;

        if (node == root) {
            // print the data of the node
            std::cout << node->data;
            std::cout << (node->color == Color::RED ? "🟥" : "🔳") << std::endl;

            // enter the next tree level - left and right branch
            printRBT(prefix + (isLeft ? "│" : ""), node->left, true);
            printRBT(prefix + (isLeft ? "│" : ""), node->right, false);
        } else {
            std::cout << (isLeft ? "├── " : "└── ") << node->data;
            std::cout << (node->color == Color::RED ? "🟥" : "🔳") << std::endl;

            printRBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
            printRBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
        }
    }
}

void RedBlackTree::printRBT() {
    printRBT("", root, false);
}

RedBlackTree::~RedBlackTree() {
    deleteTree(root);
}

void RedBlackTree::deleteTree(RBTNode *node) {
    if (node != &S) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}