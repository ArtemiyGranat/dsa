#pragma once
#include <iostream>

template<typename T>
struct Node {
    T key;
    Node<T> *left, *right;
    unsigned int height;

    Node(const T &key);
    ~Node() = default;
};

template <typename T>
class AvlTree {
public:
    AvlTree();
    ~AvlTree() = default;

    void insert(const T& key);
    void remove(const T& key);
    // AVL tree traversals
    void preorder_traversal();
    void inorder_traversal();
    void postorder_traversal();
private:
    Node<T>* root;

    int height(Node<T>* node);
    int get_balance_factor(Node<T>* node);
    Node<T>* balance_fixup(Node<T>* node);
    int height_fixup(Node<T>* node);
    Node<T>* remove_min_node(Node<T>* node);
    // AVL tree rotations
    Node<T>* left_rotate(Node<T>* node);
    Node<T>* right_rotate(Node<T>* node);
    // AVL tree insertion
    Node<T>* insert_internal(const T& key, Node<T>* current);
    // AVL tree removing
    Node<T>* next_node(Node<T>* current);
    Node<T>* remove_internal(const T& key, Node<T>* current);
    // AVL tree traversals
    void preorder_internal(Node<T>* current);
    void inorder_internal(Node<T>* current);
    void postorder_internal(Node<T>* current);
};

#include "avltree.tpp"