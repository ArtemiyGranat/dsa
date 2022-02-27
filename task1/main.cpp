#include <iostream>
#include "counting_sort.h"
#include "radix_sort.h"

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::vector<int> v(n);
    for (auto &elem : v) {
        std::cin >> elem;
    }
    std::vector<int> counting_test = v, radix_test = v;
    counting_sort(counting_test);
    std::cout << "Vector after counting sort: ";
    for (auto &elem : counting_test) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
    std::cout << "Vector after radix sort: ";
    radix_sort(radix_test);
    for (auto &elem : radix_test) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}