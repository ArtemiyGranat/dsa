#pragma once

struct DSU {
    std::vector<int> parent;
    std::vector<int> size;
    int n;

    DSU(int n) : n(n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int get(int x) {
        if (x == parent[x]) {
            return x;
        } else {
            return (parent[x] = get(parent[x])); 
        }
    }
    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            if (size[x] < size[y]) {
                std::swap(x, y);
            }
            parent[y] = x;
            size[x] += size[y];
        }
    }
};