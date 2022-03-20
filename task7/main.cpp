#include <iostream>
#include "kmp.h"

std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
    for (auto &elem : v) {
        out << elem << ' ';
    }
    out << '\n';
    return out;
}

int main() {
    std::string s, p;
    getline(std::cin, s);
    getline(std::cin, p);

    std::vector<int> indices = kmp(s, p);
    std::cout << "Pattern found at indices: " << indices;
}