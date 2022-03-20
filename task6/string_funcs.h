#pragma once
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> prefix_function(const std::string& s) {
    int sz = (int) s.length();
    std::vector<int> p(sz, 0);

    for (int i = 1; i < sz; ++i) {
        int j = p[i - 1];
        while(j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        p[i] = j;
    }
    return p;
}

std::vector<int> z_function(const std::string& s) {
    int sz = (int) s.length();
    std::vector<int> z(sz, 0);
    z[0] = sz;
    
    int l = 0, r = 0;
    for (int i = 1; i < sz; ++i) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while(i + z[i] < sz && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

std::vector<int> z_to_prefix(const std::vector<int>& z) {
    int sz = (int) z.size();
    std::vector<int> p(sz, 0);

    for (int i = 1; i < sz; ++i) {
        if (z[i] > 0) {
            for (int j = z[i] - 1; j >= 0 && p[i + j] == 0; --j) {
                p[i + j] = j + 1;
            }
        }
    }
    return p;
}

std::vector<int> prefix_to_z(const std::vector<int>& p) {
    int sz = (int) p.size();
    std::vector<int> z(sz, 0);

    for (int i = 1; i < sz; ++i) {
        if (p[i] > 0) {
            z[i - p[i] + 1] = p[i];
        }
    }
    z[0] = sz;
    for (int i = 1; i < sz; ++i) {
        int t = i;
        if (z[i] > 0) {
            for (int j = 1; j < z[i] - 1 && z[i + j] <= z[j]; j++) {
                z[i + j] = std::min(z[j], z[i] - j);
                t = i + j;
            }
        }
        i = t + 1;
    }
    return z;
}