#pragma once
#include <vector>
#include <algorithm>

template <typename T>
void merge(std::vector<T>& v, int l, int mid, int r) {
    std::vector<T> l_v(mid - l + 1), m_v(r - mid);
    for (int i = 0; i < l_v.size(); i++) {
        l_v[i] = v[l + i];
    }
    for (int i = 0; i < m_v.size(); i++) {
        m_v[i] = v[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < l_v.size() && j < m_v.size()) {
        if (l_v[i] <= m_v[j]) {
            v[k] = l_v[i];
            i++;
        } else {
            v[k] = m_v[j];
            j++;
        }
        k++;
    }
    while (i < l_v.size()) {
        v[k] = l_v[i];
        i++;
        k++;
    }
    while(j < m_v.size()) {
        v[k] = m_v[j];
        j++;
        k++;
    }
}

template <typename T>
void merge_sort(std::vector<T>& v, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        merge_sort(v, l, mid);
        merge_sort(v, mid + 1, r);
        merge(v, l, mid, r);
    }
}