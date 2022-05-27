#include <iostream>
#include <vector>

struct UnionFind {
    std::vector<long long> par, rank, num;

    UnionFind(long long N) : par(N), rank(N), num(N) {
        for (long long i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
            num[i] = 1;
        }
    }

    long long root(long long x) {
        return par[x] == x ? x : par[x] = root(par[x]);
    }

    bool same(long long x, long long y) {
        return root(x) == root(y);
    }

    long long unite(long long x, long long y) {
        x = root(x);
        y = root(y);
        long long n1 = num[x], n2 = num[y];

        if (x == y) {
            return 0;
        }

        if (rank[x] < rank[y]) {
            par[x] = y;
            num[x] += num[y];
            num[y] = num[x];
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
            num[y] += num[x];
            num[x] = num[y];
        }

        return n1 * n2;
    }
};


struct Bridge {
    long long o;
    long long d;
};

int main()
{
    long long N, M, i, A, B;
    std::cin >> N >> M;
    std::vector<Bridge> br(M);
    for (i = 0; i < M; i++) {
        std::cin >> A >> B;
        Bridge tmp = {A - 1, B - 1};
        br[i] = tmp;
    }

    std::vector<long long> ans(M + 1);
    UnionFind uf(N);
    long long dec;
    ans[M] = N * (N - 1) / 2;

    for (i = M - 1; i >= 0; i--) {
        dec = uf.unite(br[i].o, br[i].d);
        ans[i] = ans[i + 1] - dec;
    }

    for (i = 1; i < M + 1; i++) {
        std::cout << ans[i] << std::endl;
    }

    return 0;
}