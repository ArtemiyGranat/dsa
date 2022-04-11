#include <iostream>
#include "rbtree.hpp"

int main() {
    RbTree<int> rbt;
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int elem;
        std::cin >> elem;
        rbt.insert(elem);
    }
    std::cout << "Inorder traversal: \n";
    rbt.inorder_traversal();
    std::cout << '\n';
    std::cout << "Preorder traversal: \n";
    rbt.preorder_traversal();
    std::cout << '\n';
    std::cout << "Postorder traversal: \n";
    rbt.postorder_traversal();
    std::cout << '\n';
    std::cout << "Enter the number of elements to be removed: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int elem;
        std::cin >> elem;
        rbt.remove(elem);
    }
    std::cout << "Traversals after removing some elements: \n";
    std::cout << "Preorder traversal: \n";
        rbt.preorder_traversal();
}