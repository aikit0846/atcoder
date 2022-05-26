#include <iostream>
#include <vector>

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

    bool is_bridge() {
        int ne = root(0);
        for (int i = 1; i < par.size(); i++) {
            if (root(i) != ne) {
                return true;
            }
        }
        return false;
    }
};

struct Edge {
    int o;
    int d;
};

int main()
{
    int N, M, i, j, a, b, ans;
    std::cin >> N >> M;
    std::vector<Edge> E(M);
    for (i = 0; i < M; i++) {
        std::cin >> a >> b;
        Edge e = {a - 1, b - 1};
        E[i] = e;
    }

    ans = 0;
    for (i = 0; i < M; i++) {
        UnionFind uf(N);
        for (j = 0; j < M; j++) {
            if (j == i) {
                continue;
            }
            uf.unite(E[j].o, E[j].d);
        }
        if (uf.is_bridge()) {
            ans++;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}