#pragma once
#include <vector>
#include <algorithm>

template <typename T>
int partition(std::vector<T>& v, int l, int r) {
    T pivot = v[l + (r - l) / 2];
    int i = l;
    int j = r;
    while (i <= j) {
        while (v[i] < pivot) {
            i++;
        }
        while (v[j] > pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        std::swap(v[i++], v[j--]);
    }
    return j;
}

template <typename T>
void quick_sort(std::vector<T>& v, int l, int r) {
    if (l < r) {
        int pivot = partition(v, l, r);
        quick_sort(v, l, pivot);
        quick_sort(v, pivot + 1, r);
    }
}