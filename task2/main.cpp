#include <iostream>
#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"

void print_v(std::vector<int> v) {
    for (auto &elem : v) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> v(n);
    for (auto &elem : v) {
        std::cin >> elem;
    }
    std::vector<int> quick_test = v, merge_test = v, heap_test = v;

    quick_sort(quick_test, 0, v.size() - 1);
    std::cout << "Vector after quick sort: ";
    print_v(quick_test);

    merge_sort(merge_test, 0, v.size() - 1);
    std::cout << "Vector after merge sort: ";
    print_v(merge_test);

    heap_sort(heap_test, v.size());
    std::cout << "Vector after heap sort: ";
    print_v(heap_test);
}