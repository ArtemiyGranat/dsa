// BST node constructors

template <typename T>
Node<T>::Node(const T &key, Node<T>* left, Node<T>* right) {
    this->key = key;
    this->left = left;
    this->right = right;
}

template <typename T>
Node<T>::Node(const Node<T>*& node) {
    this->key = node->key;
    this->left = node->left;
    this->right = node->right;
}

// BST constructors

template <typename T>
Bst<T>::Bst() {
    root = nullptr;
}

// BST methods

template <typename T>
void Bst<T>::insert(const T& key) {
    insert_internal(key, root);
}

template <typename T>
void Bst<T>::remove(const T& key) {
    remove_internal(key, root);
}

template <typename T>
void Bst<T>::find(const T& key) {
    find_internal(key, root);
}

template <typename T>
Node<T>* Bst<T>::insert_internal(const T& key, Node<T>*& current) {
    if (current == nullptr) {
        current = new Node<T>(key);
    } else if (key < current->key) {
        current->left = insert_internal(key, current->left);
    } else {
        current->right = insert_internal(key, current->right);
    }
    return current;
}

template <typename T>
Node<T>* Bst<T>::next_node(Node<T>* current) {
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

template <typename T>
Node<T>* Bst<T>::remove_internal(const T& key, Node<T>*& current) {
    if (current == nullptr) {
        return nullptr;
    }
    Node<T>* node;
    if (key < current->key) {
        current->left = remove_internal(key, current->left);
    } else if (key > current->key) {
        current->right = remove_internal(key, current->right);
    } else {
        if (current->left == nullptr && current->right == nullptr) {
            return nullptr;
        } else if (current->left == nullptr) {
            node = current->right;
            free(current);
            return node;
        } else if (current->right == nullptr) {
            node = current->left;
            free(current);
            return node;
        }
        node = next_node(current->right);
        current->key = node->key;
        current->right = remove_internal(node->key, current->right);
    }
    return current;
}

template <typename T>
Node<T>* Bst<T>::find_internal(const T& key, Node<T>*& current) {
    if (current == nullptr || current->key == key) {
        return current;
    }
    if (current->key < key) {
        return find_internal(key, current->right);
    }
    return find_internal(key, current->left);
}

// BST traversals

template<typename T>
void Bst<T>::inorder_traversal() {
    inorder_internal(root);
}

template<typename T>
void Bst<T>::preorder_traversal() {
    preorder_internal(root);
}

template<typename T>
void Bst<T>::postorder_traversal() {
    postorder_internal(root);
}

template <typename T>
void Bst<T>::inorder_internal(Node<T>* current) {
    if (current == nullptr) {
        return;
    }
    inorder_internal(current->left);
    std::cout << current->key << ' ';
    inorder_internal(current->right);
}

template <typename T>
void Bst<T>::preorder_internal(Node<T>* current) {
    if (current == nullptr) {
        return;
    }
    std::cout << current->key << ' ';
    preorder_internal(current->left);
    preorder_internal(current->right);
}

template <typename T>
void Bst<T>::postorder_internal(Node<T>* current) {
    if (current == nullptr) {
        return;
    }
    postorder_internal(current->left);
    postorder_internal(current->right);
    std::cout << current->key << ' ';
}