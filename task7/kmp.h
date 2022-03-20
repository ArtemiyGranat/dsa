#include "string_funcs.h"

std::vector<int> kmp(const std::string& s, const std::string& pattern) {
    std::string new_s = pattern + '#' + s;
    std::vector<int> p = prefix_function(new_s);
    int sz = (int) p.size(), pat_sz = (int) pattern.length();

    std::vector<int> indices;
    for (int i = 0; i < sz; ++i) {
        if (p[i + pat_sz + 1] == pat_sz) {
            indices.push_back(i - pat_sz + 1);
        }
    }
    return indices;
}