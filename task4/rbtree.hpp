#pragma once

template<typename T>
struct RbTreeNode {
    enum Color {
        RED, BLACK
    };
    T key;
    RbTreeNode<T>* parent;
    RbTreeNode<T> *left, *right;
    Color color;
};

template <typename T>
class RbTree {
public:
    RbTree();
    ~RbTree() = default;
private:
    RbTreeNode* root;
};

#include "rbtree.tpp"