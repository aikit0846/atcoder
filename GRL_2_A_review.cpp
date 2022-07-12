#include <iostream>
#include <vector>
#include <queue>

struct UnionFind {
    std::vector<int> par, rank;

    UnionFind(int N) : par(N), rank(N) {
        for (int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int root(int x) {
        return par[x] == x ? x : par[x] = root(par[x]);
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) {
            return;
        }

        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
};

struct Edge {
    int s;
    int t;
    int w;
};

int main()
{
    int V, E, i, s, t, w, ans;
    std::cin >> V >> E;
    auto cmp = [](Edge e1, Edge e2) {
        return e1.w > e2.w;
    };
    std::priority_queue<Edge, std::vector<Edge>, decltype(cmp)> heap{cmp};
    for (i = 0; i < E; i++) {
        std::cin >> s >> t >> w;
        Edge e = {s, t, w};
        heap.push(e);
    }

    UnionFind uf(V);
    ans = 0;
    while (!heap.empty()) {
        Edge nowe = heap.top();
        heap.pop();

        if (!uf.same(nowe.s, nowe.t)) {
            uf.unite(nowe.s, nowe.t);
            ans += nowe.w;
        }
    }

    std::cout << ans << std::endl;
}