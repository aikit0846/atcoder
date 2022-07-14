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
};

int main()
{
    int n, q, i, com, x, y;
    std::cin >> n >> q;

    UnionFind uf(n);
    for (i = 0; i < q; i++) {
        std::cin >> com >> x >> y;
        if (com) {
            std::cout << uf.same(x, y) << std::endl;
        } else {
            uf.unite(x, y);
        }
    }

    return 0;
}