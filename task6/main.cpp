#include <iostream>
#include "string_funcs.h"

std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
    for (auto &elem : v) {
        out << elem << ' ';
    }
    out << '\n';
    return out;
}

int main() {
    std::string s;
    getline(std::cin, s);

    std::vector<int> pr, z, pr2z, z2pr;
    pr = prefix_function(s);
    std::cout << "Prefix function: " << pr;

    z = z_function(s);
    std::cout << "Z-function: " << z;

    z2pr = z_to_prefix(z);
    std::cout << "Z-function to prefix-function: " << z2pr;

    pr2z = prefix_to_z(pr);
    std::cout << "Prefix-function to Z-function: " << pr2z;
}