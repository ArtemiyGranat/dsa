#include <vector>
#include <algorithm>

void counting_sort(std::vector<int>& v) { 
    int max_elem = *max_element(v.begin(), v.end()); 
    int min_elem = *min_element(v.begin(), v.end()); 
    std::vector<int> count_v(max_elem - min_elem + 1, 0);
    for (auto elem : v) {
        count_v[elem - min_elem]++;
    }
    for (int i = 1; i < count_v.size(); i++) {
        count_v[i] += count_v[i - 1];
    }
    std::vector<int> tmp_v = v;
    for (int i = v.size() - 1; i >= 0; i--) {
        v[--count_v[tmp_v[i] - min_elem]] = tmp_v[i];
    }
}
