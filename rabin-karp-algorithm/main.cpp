#include <iostream>
#include "rabin-karp.h"

int main() {
    std::string s, pattern;
    std::vector<int> indices;
    
    std::cout << "Enter the string and pattern: ";
    std::cin >> s >> pattern;
    indices = rabin_karp(s, pattern);
    if (indices.size() != 0) {
        std::cout << "Pattern found at indices: ";
        for (auto &index: indices) {
            std::cout << index << ' ';
        }
    } else {
        std::cout << "Pattern is not found";
    }
    std::cout << '\n';
}