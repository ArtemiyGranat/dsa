#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int PRIME = 13;

long long pow(long long p_power, int m) {
    p_power = 1;
    for (int i = 1; i <= m; ++i) {
        p_power = (p_power * PRIME) % MOD;
        if (p_power < 0) {
            p_power += MOD;
        }
    }
    return p_power;
}

long long polynomial_hash(const std::string& s, int i) {
    long long hash = 0;
    for (int j = 0; j <= i; ++j) {
        hash = (hash * PRIME + int(s[j])) % MOD;
        if (hash < 0) {
            hash += MOD;
        }
    }
    return hash;
}

std::vector<int> rabin_karp(const std::string& s, const std::string& pattern) {
    int m = pattern.size(), n = s.size();
    long long p_power = pow(p_power, m);
    std::vector<long long> precalc(n, 0);
    for (int i = 0; i < n; i++) {
        precalc[i] = polynomial_hash(s, i);
    }
    long long pattern_hash = polynomial_hash(pattern, m - 1);
    std::vector<int> indices;
    for (int i = 0; i <= n - m; ++i) {
        long long hash = (precalc[i + m - 1] - ((i == 0) ? 0 : precalc[i - 1]) * p_power) % MOD;
        if (hash < 0) {
            hash += MOD;
        }
        if (hash == pattern_hash) {
            // if (pattern == s.substr(i, m)) {
                indices.push_back(i);
            // }
        }
    }
    return indices;
}