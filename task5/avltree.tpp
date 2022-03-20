// AVL tree and AVL tree's node constructors

template <typename T>
Node<T>::Node(const T &key) {
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}

template <typename T>
AvlTree<T>::AvlTree() {
    root = nullptr;
}

template <typename T>
int AvlTree<T>::height(Node<T>* node) {
    return (node == nullptr) ? 0 : node->height;
}

template <typename T>
int AvlTree<T>::get_balance_factor(Node<T>* node) {
    return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

template <typename T>
int AvlTree<T>::height_fixup(Node<T>* node) {
    return 1 + std::max(height(node->left), height(node->right));
}

template<typename T>
Node<T>* AvlTree<T>::balance_fixup(Node<T>* current) {
    current->height = 1 + std::max(height(current->left), height(current->right));
    if (get_balance_factor(current) == 2) {
        if (get_balance_factor(current->left) < 0) {
            current->left = left_rotate(current->left);
        }
        return right_rotate(current);
    }
    if (get_balance_factor(current) == -2) {
        if (get_balance_factor(current->right) > 0) {
            current->right = right_rotate(current->right);
        }
        return left_rotate(current);
    }
    return current;
}

template <typename T>
Node<T>* AvlTree<T>::next_node(Node<T>* current) {
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// AVL tree rotations

template <typename T>
Node<T>* AvlTree<T>::right_rotate(Node<T>* node) {
    Node<T>* tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    node->height = height_fixup(node);
    tmp->height = height_fixup(tmp);
    return tmp;
}

template <typename T>
Node<T>* AvlTree<T>::left_rotate(Node<T>* node) {
    Node<T>* tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    node->height = height_fixup(node);
    tmp->height = height_fixup(tmp);
    return tmp;
}


// AVL tree insertion

template <typename T>
void AvlTree<T>::insert(const T& key) {
    root = insert_internal(key, root);
}

template <typename T>
Node<T>* AvlTree<T>::insert_internal(const T& key, Node<T>* current) {
    if (current == nullptr) {
        current = new Node<T>(key);
    } else if (key < current->key) {
        current->left = insert_internal(key, current->left);
    } else if (key > current->key) {
        current->right = insert_internal(key, current->right);
    }
    return balance_fixup(current);
}

// AVL tree removing

template <typename T>
void AvlTree<T>::remove(const T& key) {
    root = remove_internal(key, root);
}

template <typename T>
Node<T>* AvlTree<T>::remove_min_node(Node<T>* node) {
    if (node->left == nullptr) {
        return node->right;
    }
    node->left = remove_min_node(node->left);
    return balance_fixup(node);
}

template <typename T>
Node<T>* AvlTree<T>::remove_internal(const T& key, Node<T>* current) {
    if (current == nullptr) {
        return nullptr;
    }
    Node<T>* node;
    if (key < current->key) {
        current->left = remove_internal(key, current->left);
    } else if (key > current->key) {
        current->right = remove_internal(key, current->right);
    } else {
        Node<T> *left = current->left, *right = current->right;
        free(current);
        if (right == nullptr) {
            return left;
        }
        Node<T>* next = next_node(right);
        next->right = remove_min_node(right);
        next->left = left;
        return balance_fixup(next);
    }
    return balance_fixup(current);
}

// AVL tree traversals

template<typename T>
void AvlTree<T>::inorder_traversal() {
    inorder_internal(root);
}

template<typename T>
void AvlTree<T>::preorder_traversal() {
    preorder_internal(root);
}

template<typename T>
void AvlTree<T>::postorder_traversal() {
    postorder_internal(root);
}

template <typename T>
void AvlTree<T>::inorder_internal(Node<T>* current) {
    if (current == nullptr) {
        return;
    }
    inorder_internal(current->left);
    std::cout << current->key << ' ';
    inorder_internal(current->right);
}

template <typename T>
void AvlTree<T>::preorder_internal(Node<T>* current) {
    if (current == nullptr) {
        return;
    }
    std::cout << current->key << ' ';
    preorder_internal(current->left);
    preorder_internal(current->right);
}

template <typename T>
void AvlTree<T>::postorder_internal(Node<T>* current) {
    if (current == nullptr) {
        return;
    }
    postorder_internal(current->left);
    postorder_internal(current->right);
    std::cout << current->key << ' ';
}