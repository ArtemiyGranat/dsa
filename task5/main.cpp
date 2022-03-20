#include "avltree.hpp"

int main() {
    AvlTree<int> avl;
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int elem;
        std::cin >> elem;
        avl.insert(elem);
    }
    std::cout << "Inorder traversal: ";
    avl.inorder_traversal();
    std::cout << '\n';
    std::cout << "Preorder traversal: ";
    avl.preorder_traversal();
    std::cout << '\n';
    std::cout << "Postorder traversal: ";
    avl.postorder_traversal();
    std::cout << '\n';
    std::cout << "Enter the number of elements to be removed: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int elem;
        std::cin >> elem;
        avl.remove(elem);
    }
    std::cout << "Traversals after removing some elements: \n";
    std::cout << "Preorder traversal: ";
    avl.preorder_traversal();
    std::cout << '\n';
}