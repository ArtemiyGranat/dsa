#pragma once
#include <vector>
#include <algorithm>
#include "dsu.h"
#include "edge.h"

std::vector<Edge> dsu_kruskal(std::vector<Edge> edges, int n, int m) {
    DSU dsu(n);
    std::sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    std::vector<Edge> mst;

    for (int i = 0; i < m; ++i) {
        if (dsu.get(edges[i].from - 1) != dsu.get(edges[i].to - 1)) {
            mst.push_back(edges[i]);
            dsu.unite(edges[i].from - 1, edges[i].to - 1);
        }
    }
    return mst;
}