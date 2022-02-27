#include <vector>
#include <algorithm>

void heapify(std::vector<int>& v, int n, int i) {
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && v[l] > v[max]) {
        max = l;
    }
    if (r < n && v[r] > v[max]) {
        max = r;
    }
    if (max != i) {
        std::swap(v[i], v[max]);
        heapify(v, n, max);
    }
}

void heap_sort(std::vector<int>& v, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        std::swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}