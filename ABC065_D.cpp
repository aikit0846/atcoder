#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


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


struct City {
    int id;
    int x;
    int y;
};


struct Edge {
    int s;
    int t;
    int l;
};


int main()
{
    int N, x, y, i, ans;
    std::cin >> N;
    std::vector<City> C(N);
    for (i = 0; i < N; i++) {
        std::cin >> x >> y;
        City c = {i, x, y};
        C[i] = c;
    }

    auto cmpEdge = [](Edge e1, Edge e2) {
        return e1.l > e2.l;
    };
    auto cmpCityx = [](City &c1, City &c2) {
        return c1.x < c2.x;
    };
    auto cmpCityy = [](City &c1, City &c2) {
        return c1.y < c2.y;
    };
    std::priority_queue<Edge, std::vector<Edge>, decltype(cmpEdge)> pq{cmpEdge};

    std::sort(C.begin(), C.end(), cmpCityx);
    for (i = 0; i < N - 1; i++) {
        Edge e = {C[i].id, C[i + 1].id, C[i + 1].x - C[i].x};
        pq.push(e);
    }
    std::sort(C.begin(), C.end(), cmpCityy);
    for (i = 0; i < N - 1; i++) {
        Edge e = {C[i].id, C[i + 1].id, C[i + 1].y - C[i].y};
        pq.push(e);
    }

    ans = 0;
    UnionFind uf(N);
    while (uf.gnum > 1 && !pq.empty()) {
        Edge min_e = pq.top();
        pq.pop();
        if (uf.unite(min_e.s, min_e.t)) {
            ans += min_e.l;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}