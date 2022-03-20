#include <iostream>
#include "counting_sort.h"
#include "radix_sort.h"

std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
    for (auto &elem : v) {
        out << elem << ' ';
    }
    out << '\n';
    return out;
}

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
    std::cout << "Vector after counting sort: " << counting_test;
    
    radix_sort(radix_test);
    std::cout << "Vector after radix sort: " << radix_test;
}