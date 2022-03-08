#pragma once

enum Color {
    RED, BLACK
};

template<typename T>
struct Node {
    T key;
    Node<T>* parent;
    Node<T> *left, *right;
    Color color;

    Node();
    Node(const T &key, Node<T>* left, Node<T>* right,
        Node<T>* parent, Color color);
    Node(const Node<T>*& node);
    ~Node() = default;
};

template <typename T>
class RbTree {
public:
    RbTree();
    ~RbTree() = default;
    void insert(const T& key);
    void remove(const T& key);
    void preorder_traversal();
    void inorder_traversal();
    void postorder_traversal();

private:
    Node<T>* root;
    Node<T>* nil;
    Node<T>* bst_insert(const T& key);
    void insert_fixup(Node<T>* node);
    void left_rotate(Node<T>* node);
    void right_rotate(Node<T>* node);
    Node<T>* next_node(Node<T>* current);
    void remove_fixup(Node<T>* node); // need a reference maybe
    void remove_internal(Node<T>*& node);
    Node<T>* find(const T& key, Node<T>*& current);
    void preorder_internal(Node<T>* current);
    void inorder_internal(Node<T>* current);
    void postorder_internal(Node<T>* current);
};

#include "rbtree.tpp"