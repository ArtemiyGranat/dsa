#include <iostream>
#include "boyer-moore.h"

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
    std::vector<int> indices = boyer_moore(s, p);
    if (indices.size() > 0) {
        std::cout << "Pattern found at indices " << indices;
    } else {
        std::cout << "Pattern is not found" << '\n';
    }
}