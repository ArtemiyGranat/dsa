#include <string>
#include <vector>
#include <algorithm>

const int ALPHABET_SIZE = 256;

void precalc_stop_table(const std::string& s, std::vector<int>& table) {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        table[i] = s.length();
    }
    for (int i = 0; i < s.length(); ++i) {
        table[(int) s[i]] = s.length() - 1 - i;
    }
}

bool is_prefix(const std::string& s, int pos) {
    int suff_len = s.length() - pos;
    for (int i = 0; i < suff_len; ++i) {
        if (s[i] != s[pos + i]) {
            return false;
        }
    }
    return true;
}

unsigned suffix_length(const std::string& s, unsigned pos) {
    int i = 0;
    while (s[pos - i] == s[s.length() - 1 - i] && i < pos) {
        ++i;
    }
    return i;
}

void precalc_suff_table(const std::string& s, std::vector<int>& table) {
    int last_prefix_index = 1;
    for (int p = s.length() - 1; p >= 0; --p) {
        if (is_prefix(s, p + 1)) {
            last_prefix_index = p + 1;
        }
        table[p] = last_prefix_index + (s.length() - 1 - p);
    }
    for (int p = 0; p < s.length() - 1; ++p) {
        int suff_len = suffix_length(s, p);
        if (s[p - suff_len] != s[s.length() - 1 - suff_len]) {
            table[s.length() - 1 - suff_len] = s.length() - 1 - p + suff_len;
        }
    }
}

std::vector<int> boyer_moore(const std::string& s, const std::string& p) {
    if (s.length() == 0 || p.length() == 0 || s.length() < p.length()) {
        return {};
    }
    std::vector<int> indices;
    std::vector<int> stop_table(ALPHABET_SIZE, p.length());
    std::vector<int> suffix_table(s.length());

    precalc_stop_table(p, stop_table);
    precalc_suff_table(p, suffix_table);

    int i = p.length() - 1;
    while (i < s.length()) {
        int j = p.length() - 1;
        while (j >= 0 && s[i] == p[j]) {
            --i;
            --j;
        }
        if (j < 0) {
            indices.push_back(i + 1);
            i += p.length() + 1;
            continue;
        }
        int shift = std::max(stop_table[(int) s[i]], suffix_table[j]);
        i += shift;
    }
    return indices;
}