#include <iostream>
#include <algorithm>
#include "simple_kruskal.h"
#include "dsu_kruskal.h"

std::ostream& operator<<(std::ostream& out, const std::vector<Edge>& v) {
    for (auto &elem : v) {
        out << elem.from << ' ' << elem.to << ' ' << elem.weight << '\n';
    }
    out << '\n';
    return out;
}

int main() {
    int n, m;
    std::cout << "Enter the number of vertices and edges: ";
    std::cin >> n >> m;
    std::vector<Edge> edges(m);
    std::cout << "Enter edges in the format \"from to weight\":";
    for (int i = 0; i < m; ++i) {
        std::cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }
    std::cout << "Minimum spanning tree of this graph: \n";
    std::cout << dsu_kruskal(edges, n, m);
}

/*
Input:
5 7
1 2 3
1 5 1
2 5 4
2 3 5
3 4 2
4 5 7
3 5 6

Output:
1 5 1
3 4 2
1 2 3
2 3 5
*/