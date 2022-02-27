// BST node constructors

template <typename T>
BstNode<T>::BstNode(const T &key, BstNode<T>* left, BstNode<T>* right) {
    this->key = key;
    this->left = left;
    this->right = right;
}

template <typename T>
BstNode<T>::BstNode(const BstNode<T>*& node) {
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
BstNode<T>* Bst<T>::insert_internal(const T& key, BstNode<T>*& current) {
    if (current == nullptr) {
        current = new BstNode<T>(key);
    }
    else if (key < current->key) {
        current->left = insert_internal(key, current->left);
    }
    else {
        current->right = insert_internal(key, current->right);
    }
    return current;
}

template <typename T>
BstNode<T>* Bst<T>::min_key_node(BstNode<T>* current) {
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

template <typename T>
BstNode<T>* Bst<T>::remove_internal(const T& key, BstNode<T>*& current) {
    if (current == nullptr) {
        return nullptr;
    }
    BstNode<T>* tmp;
    if (key < current->key) {
        current->left = remove_internal(key, current->left);
    }
    else if (key > current->key) {
        current->right = remove_internal(key, current->right);
    }
    else {
        if (current->left == nullptr && current->right == nullptr) {
            return nullptr;
        }
        else if (current->left == nullptr) {
            tmp = current->right;
            free(current);
            return tmp;
        }
        else if (current->right == nullptr) {
            tmp = current->left;
            free(current);
            return tmp;
        }
        tmp = min_key_node(current->right);
        current->key = tmp->key;
        current->right = remove_internal(tmp->key, current->right);
    }
    return current;
}

template <typename T>
BstNode<T>* Bst<T>::find_internal(const T& key, BstNode<T>*& current) {
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
void Bst<T>::inorder_internal(BstNode<T>* current) {
    if (current == nullptr) {
        return;
    }
    inorder_internal(current->left);
    std::cout << current->key << ' ';
    inorder_internal(current->right);
}

template <typename T>
void Bst<T>::preorder_internal(BstNode<T>* current) {
    if (current == nullptr) {
        return;
    }
    std::cout << current->key << ' ';
    preorder_internal(current->left);
    preorder_internal(current->right);
}

template <typename T>
void Bst<T>::postorder_internal(BstNode<T>* current) {
    if (current == nullptr) {
        return;
    }
    postorder_internal(current->left);
    postorder_internal(current->right);
    std::cout << current->key << ' ';
}