#pragma once
#include <iostream>

template <typename T>
struct BstNode { // binary search tree node
    T key;
    BstNode<T> *left, *right; // left and right child of node

    BstNode() = default;
    BstNode(const T &key, BstNode<T>* left = nullptr, BstNode<T>* right = nullptr);
    BstNode(const BstNode<T>*& node);
    ~BstNode() = default;
};

template <typename T>
class Bst { // binary search tree
public:
    Bst();
    ~Bst() = default;
    
    void insert(const T& key);
    void remove(const T& key);
    void find(const T& key);
    void inorder_traversal();
    void preorder_traversal();
    void postorder_traversal();
private:
    BstNode<T>* root;
    BstNode<T>* min_key_node(BstNode<T>* current);
    BstNode<T>* insert_internal(const T& key, BstNode<T>*& current);
    BstNode<T>* remove_internal(const T& key, BstNode<T>*& current);
    BstNode<T>* find_internal(const T& key, BstNode<T>*& current);
    void inorder_internal(BstNode<T>* current);
    void preorder_internal(BstNode<T>* current);
    void postorder_internal(BstNode<T>* current);
};

#include "bst.tpp"