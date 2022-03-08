// std::cout overload for color

std::ostream &operator <<(std::ostream& s, Color c) {
    const std::string color[] = { "Red", "Black" };
    return s << color[c];
}

// Red-black tree and red-black tree's node constructors

template <typename T>
Node<T>::Node() {
    this->key = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

template <typename T>
Node<T>::Node(const T &key, Node<T>* left, Node<T>* right,
              Node<T>* parent, Color color) {
    this->key = key;
    this->left = left;
    this->right = right;
    this->parent = parent;
    this->color = color;
}

template <typename T>
Node<T>::Node(const Node<T>*& node) {
    this->key = node->key;
    this->left = node->left;
    this->right = node->right;
    this->parent = node->parent;
    this->color = node->color;
}

template <typename T>
RbTree<T>::RbTree() {
    nil = new Node<T>();
    nil->color = BLACK;
    root = nil;
}

// Red-black tree rotations

template <typename T>
void RbTree<T>::left_rotate(Node<T>* node) {
    Node<T>* right_child = node->right;
    node->right = right_child->left;
    if (node->right != nil) {
        node->right->parent = node;
    }
    if (right_child != nil) {
        right_child->parent = node->parent;
    }
    if (node->parent == nil) {
        root = right_child;
    } else if (node == node->parent->left) {
        node->parent->left = right_child;
    } else {
        node->parent->right = right_child;
    }
    right_child->left = node;
    if (node != nil) {
        node->parent = right_child;
    }
}

template <typename T>
void RbTree<T>::right_rotate(Node<T>* node) {
    Node<T>* left_child = node->left;
    node->left = left_child->right;
    if (node->left != nil) {
        node->left->parent = node;
    }
    if (left_child != nil) {
        left_child->parent = node->parent;
    }
    if (node->parent == nil) {
        root = left_child;
    } else if (node == node->parent->left) {
        node->parent->left = left_child;
    } else {
        node->parent->right = left_child;
    }
    left_child->right = node;
    if (node != nil) {
        node->parent = left_child;
    }
}

// Red-black tree insertion

template<typename T>
Node<T>* RbTree<T>::bst_insert(const T& key) {
    Node<T>* tmp;
    Node<T>* current = root;
    Node<T>* new_node = new Node<T>(key, nil, nil, nil, RED);
    while (current != nil) {
        tmp = current;
        if (current->key < new_node->key) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    if (tmp->key < new_node->key) {
        tmp->right = new_node;
    } else {
        tmp->left = new_node;
    }
    new_node->parent = tmp;
    return new_node;
}

template <typename T>
void RbTree<T>::insert_fixup(Node<T>* node) {
    Node<T> *parent = node->parent, *grandparent = parent->parent, *uncle;
    if (node == root || parent->color == BLACK) {
        root->color = BLACK;
        return;
    }
    if (parent == grandparent->right) {
        uncle = grandparent->left;
        if (uncle->color == RED) {
            uncle->color = BLACK;
            parent->color = BLACK;
            grandparent->color = RED;
            insert_fixup(grandparent);
        } else {
            grandparent->color = RED;
            if (node == parent->left) {
                right_rotate(parent);
                node->color = BLACK;
            } else {
                parent->color = BLACK;
            }
            left_rotate(grandparent);
        }
    } else {
        uncle = grandparent->right;
        if (uncle->color == RED) {
            uncle->color = BLACK;
            parent->color = BLACK;
            grandparent->color = RED;
            insert_fixup(grandparent);
        } else {
            grandparent->color = RED;
            if (node == parent->right) {
                left_rotate(parent);
                node->color = BLACK;
            }
            else {
                parent->color = BLACK;
            }
            right_rotate(grandparent);
        }
    }
}

template <typename T>
void RbTree<T>::insert(const T& key) {
    if (root == nil) {
        root = new Node<T>(key, nil, nil, nil, BLACK);
    } else {
        Node<T>* new_node = bst_insert(key);
        insert_fixup(new_node);
    }
}

// Red-black tree searching

template <typename T>
Node<T>* RbTree<T>::find(const T& key, Node<T>*& current) {
    if (current == nullptr || current->key == key) {
        return current;
    }
    if (current->key < key) {
        return find(key, current->right);
    }
    return find(key, current->left);
}

// Red-black tree removing

template <typename T>
Node<T>* RbTree<T>::next_node(Node<T>* current) {
    while (current->right != nil) {
        current = current->right;
    }
    return current;
}

template <typename T>
void RbTree<T>::remove_fixup(Node<T>* node) {
    if (node->color == RED || node == root) {
        root->color = BLACK;
        return;
    }
    Node<T> *parent = node->parent, *sibling, *left_nephew, *right_nephew;
    if (node == parent->left) {
        sibling = parent->right;
        if (sibling->color == RED) {
            sibling->color = BLACK;
            parent->color = RED;
            left_rotate(parent);
            parent = node->parent;
            sibling = parent->right;
        }
        left_nephew = sibling->left, right_nephew = sibling->right;
        if (left_nephew->color == BLACK && right_nephew->color == BLACK) {
            sibling->color = RED;
            remove_fixup(parent);
            parent->color = BLACK;
            return;
        } else if (right_nephew->color == BLACK) {
            left_nephew->color == BLACK;
            sibling->color = RED;
            right_rotate(sibling);
            sibling = parent->right;
            right_nephew = sibling->right;
        }
        sibling->color = parent->color;
        parent->color = BLACK;
        right_nephew->color = BLACK;
        left_rotate(parent);
    } else {
        sibling = parent->left;
        if (sibling->color == RED) {
            sibling->color = BLACK;
            parent->color = RED;
            right_rotate(parent);
            parent = node->parent;
            sibling = parent->left;
        }
        left_nephew = sibling->left, right_nephew = sibling->right;
        if (left_nephew->color == BLACK && right_nephew->color == BLACK) {
            sibling->color = RED;
            remove_fixup(parent);
            parent->color = BLACK;
            return;
        } else if (left_nephew->color == BLACK) {
            right_nephew->color == BLACK;
            sibling->color = RED;
            left_rotate(sibling);
            sibling = parent->left;
            left_nephew = sibling->left;
        }
        sibling->color = parent->color;
        parent->color = BLACK;
        left_nephew->color = BLACK;
        right_rotate(parent);
    }
}

template<typename T>
void RbTree<T>::remove(const T& key) {
    Node<T>* node = find(key, root);
    remove_internal(node);
}

template <typename T>
void RbTree<T>::remove_internal(Node<T>*& node) {
    if (node == nil) {
        return;
    }
    Node<T> *parent = node->parent;
    if (node->left == nil && node->right == nil) {
        remove_fixup(node);
        if (node == root) {
            root = nil;
        } else {
            if (node == parent->left) {
                parent->left = nil;
            } else {
                parent->right = nil;
            }
        }
    } else if (node->left == nil || node->right == nil) {
        Node<T>* children;
        if (node->left != nil) {
            children = node->left;
        } else {
            children = node->right;
        }
        if (node == root) {
            root = children;
        } else {
            if (node == parent->left) {
                parent->left = children;
            }
            else {
                parent->right = children;
            }
        }
        remove_fixup(children);
        children->color = BLACK;
    } else {
        Node<T>* next = next_node(node->left);
        node->key = next->key;
        remove_internal(next);
        return;
    }
    free(node);
}

// Red-black tree traversals

template<typename T>
void RbTree<T>::inorder_traversal() {
    inorder_internal(root);
}

template<typename T>
void RbTree<T>::preorder_traversal() {
    preorder_internal(root);
}

template<typename T>
void RbTree<T>::postorder_traversal() {
    postorder_internal(root);
}

template <typename T>
void RbTree<T>::inorder_internal(Node<T>* current) {
    if (current == nil) {
        return;
    }
    inorder_internal(current->left);
    std::cout << current->key << " - " << current->color << '\n';
    inorder_internal(current->right);
}

template <typename T>
void RbTree<T>::preorder_internal(Node<T>* current) {
    if (current == nil) {
        return;
    }
    std::cout << current->key << " - " << current->color << '\n';
    preorder_internal(current->left);
    preorder_internal(current->right);
}

template <typename T>
void RbTree<T>::postorder_internal(Node<T>* current) {
    if (current == nil) {
        return;
    }
    postorder_internal(current->left);
    postorder_internal(current->right);
    std::cout << current->key << " - " << current->color << '\n';
}