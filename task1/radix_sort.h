#include <vector>
#include <algorithm>

void counting_sort(std::vector<int>& v, int place) {
    std::vector<int> count_v(10, 0);
    for (auto elem : v) {
        count_v[(elem / place) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count_v[i] += count_v[i - 1];
    }
    std::vector<int> tmp_v = v;
    for (int i = v.size() - 1; i >= 0; i--) {
        v[--count_v[(tmp_v[i] / place) % 10]] = tmp_v[i];
    }
}

void radix_sort(std::vector<int>& v) {
    int max_elem = *max_element(v.begin(), v.end());
    for (int place = 1; max_elem / place > 0; place *= 10) {
        counting_sort(v, place);
    }
}