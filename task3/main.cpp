#include "bst.hpp"

int main() {
    Bst<int> bst;
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int elem;
        std::cin >> elem;
        bst.insert(elem);
    }
    std::cout << "Inorder traversal: ";
    bst.inorder_traversal();
    std::cout << '\n';
    std::cout << "Preorder traversal: ";
    bst.preorder_traversal();
    std::cout << '\n';
    std::cout << "Postorder traversal: ";
    bst.postorder_traversal();
    std::cout << '\n';
    std::cout << "Enter the number of elements to be removed: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int elem;
        std::cin >> elem;
        bst.remove(elem);
    }
    std::cout << "Traversals after removing some elements: \n";
    std::cout << "Preorder traversal: ";
    bst.preorder_traversal();
    std::cout << '\n';
}

/*
Enter the number of elements: 5
6 1 2 3 4 
Inorder traversal: 1 2 3 4 6 
Preorder traversal: 6 1 2 3 4 
Postorder traversal: 4 3 2 1 6 
Enter the number of elements to be removed: 1
2
Traversals after removing some elements: 
Preorder traversal: 6 1 3 4
*/