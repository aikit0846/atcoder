#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stdio.h>

struct UnionFind {
    std::vector<int> par, rank;
    int gnum;

    UnionFind(int N) : par(N), rank(N) {
        for (int i; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
        }
        gnum = N;
    }

    int root(int x) {
        return par[x] == x ? x : par[x] = root(par[x]);
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);

        if (x == y) {
            return false;
        }

        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
        gnum--;

        return true;
    }
};


struct Edge {
    int s;
    int t;
    double l;
};


struct Cell {
    double x;
    double y;
    double z;
    double r;
};


int main()
{
    int n, i, j;
    double x, y, z, r, dis2, rad, ans;
    
    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }

        std::vector<Cell> C(n);
        for (i = 0; i < n; i++) {
            std::cin >> x >> y >> z >> r;
            Cell c = {x, y, z, r};
            C[i] = c;

        }

        auto cmp = [](Edge e1, Edge e2) {
            return e1.l > e2.l;
        };
        std::priority_queue<Edge, std::vector<Edge>, decltype(cmp)> pq{cmp};
        UnionFind uf(n);
        for (i = 0; i < n - 1; i++) {
            for (j = i; j < n; j++) {
                dis2 = (C[i].x - C[j].x) * (C[i].x - C[j].x) + (C[i].y - C[j].y) * (C[i].y - C[j].y) + (C[i].z - C[j].z) * (C[i].z - C[j].z);
                rad = C[i].r + C[j].r;
                if (dis2 <= rad * rad) {
                    uf.unite(i, j);
                } else {
                    Edge e = {i, j, std::sqrt(dis2) - rad};
                    pq.push(e);
                }
            }
        }

        ans = 0.000;
        while (uf.gnum > 1 && !pq.empty()) {
            Edge min_e = pq.top();
            pq.pop();
            if (uf.unite(min_e.s, min_e.t)) {
                ans += min_e.l;
            }
        }

        printf("%.3f\n", ans);
    }

    return 0;
}