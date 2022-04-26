#pragma once
#include <vector>
#include <algorithm>
#include "edge.h"

std::vector<Edge> simple_kruskal(std::vector<Edge> edges, int n, int m) {
    std::sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    std::vector<Edge> mst;

    std::vector<int> id(n);
    for (int i = 0; i < n; ++i) {
        id[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        if (id[edges[i].from - 1] != id[edges[i].to - 1]) {
            mst.push_back(edges[i]);

            int old_id = id[edges[i].to - 1], new_id = id[edges[i].from - 1];
            for (int j = 0; j < n; ++j)
                if (id[j] == old_id)
                    id[j] = new_id;
        }
    }
    return mst;
}