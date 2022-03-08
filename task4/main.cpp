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
    rbt.inorder_traversal();
    std::cout << '\n';
    rbt.preorder_traversal();
    std::cout << '\n';
    rbt.postorder_traversal();
}

/*
9
8 5 15 12 19 9 13 23 10
1
12

5 - Black
8 - Red
9 - Black
10 - Red
12 - Black
13 - Black
15 - Red
19 - Black
23 - Red

10 - Black
8 - Red
5 - Black
9 - Black
15 - Red
13 - Black
19 - Black
23 - Red
*/