#pragma once
#include <iostream>

template <typename T>
struct Node { // binary search tree node
    T key;
    Node<T> *left, *right; // left and right child of node

    Node() = default;
    Node(const T &key, Node<T>* left = nullptr, Node<T>* right = nullptr);
    Node(const Node<T>*& node);
    ~Node() = default;
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
    Node<T>* root;
    Node<T>* next_node(Node<T>* current);
    Node<T>* insert_internal(const T& key, Node<T>*& current);
    Node<T>* remove_internal(const T& key, Node<T>*& current);
    Node<T>* find_internal(const T& key, Node<T>*& current);
    void inorder_internal(Node<T>* current);
    void preorder_internal(Node<T>* current);
    void postorder_internal(Node<T>* current);
};

#include "bst.tpp"