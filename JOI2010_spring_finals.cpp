#include <iostream>
#include <vector>
#include <queue>

struct UnionFind {
    std::vector<int> par, rank;
    int gnum;

    UnionFind(int N) : par(N), rank(N) {
        for (int i = 0; i < N; i++) {
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
        gnum--;
    }
};


struct Edge {
    int A;
    int B;
    int C;
};


int main()
{
    int N, M, K, i, A, B, C, ans;
    std::cin >> N >> M >> K;

    auto cmp = [](Edge e1, Edge e2) {
        return e1.C > e2.C;
    };
    std::priority_queue<Edge, std::vector<Edge>, decltype(cmp)> E{cmp};
    for (i = 0; i < M; i++) {
        std::cin >> A >> B >> C;
        Edge e = {A - 1, B - 1, C};
        E.push(e);
    }

    ans = 0;
    UnionFind uf(N);
    while (uf.gnum != K) {
        Edge mine = E.top();
        E.pop();
        if (!uf.same(mine.A, mine.B)) {
            uf.unite(mine.A, mine.B);
            ans += mine.C;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}