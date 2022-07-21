#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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

    std::map<int, std::vector<int>> group_members() {
        std::map<int, std::vector<int>> retmap;
        for (int i = 0; i < par.size(); i++) {
            retmap[root(i)].emplace_back(i);
        }
        return retmap;
    }
};

int main()
{
    int N, M, i, pin, xin, yin, ans;
    std::cin >> N >> M;
    std::vector<int> p(N);
    for (i = 0; i < N; i++) {
        std::cin >> pin;
        p[i] = pin - 1;
    }
    UnionFind uf(N);
    for (i = 0; i < M; i++) {
        std::cin >> xin >> yin;
        uf.unite(xin - 1, yin - 1);
    }

    std::map<int, std::vector<int>> g_mem = uf.group_members();
    ans = 0;
    for (auto itr1 = g_mem.begin(); itr1 != g_mem.end(); itr1++) {
        std::vector<int> p_mem, intersection;
        for (auto itr2 = itr1->second.begin(); itr2 != itr1->second.end(); itr2++) {
            p_mem.emplace_back(p[*itr2]);
        }
        std::sort(itr1->second.begin(), itr1->second.end());
        std::sort(p_mem.begin(), p_mem.end());
        std::set_intersection(itr1->second.begin(), itr1->second.end(), p_mem.begin(), p_mem.end(), std::back_inserter(intersection));
        ans += intersection.size();
    }

    std::cout << ans << std::endl;

    return 0;
}