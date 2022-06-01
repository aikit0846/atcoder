// 解けてない

#include <iostream>
#include <vector>
#include <stack>

const long long MOD = 1e9 + 7;


struct Edge {
    long long t;
    long long subtree_size;
};


long long modpow(long long a, long long n, long long m)
{
    long long res = 1;

    while (n > 0) {
        if (n & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }

    return res;
}


long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0, t;

    while (b) {
        t = a / b;
        a -= t * b;
        u -= t * v;
        std::swap(a, b);
        std::swap(u, v);
    }

    u %= m;
    if (u < 0) {
        u += m;
    }

    return u;
}


void dfs(std::vector<std::vector<Edge>> E, Edge e, long long p, long long d, std::vector<long long> &depth)
{
    depth[e.t] = d;
    for (auto &&nv : E[e.t]) {
        if (nv.t != p) {
            dfs(E, nv, e.t, d + 1, depth);
        }
    }

    e.subtree_size = 1;
    for (auto &&c : E[e.t]) {
        if (c.t != p) {
            e.subtree_size += c.subtree_size;
        }
    }
}


int main()
{
    long long N, i, A, B, x, y, z, nv, count, xe;
    std::cin >> N;
    std::vector<std::vector<Edge>> E(N);
    for (i = 0; i < N - 1; i++) {
        std::cin >> A >> B;
        Edge e1 = {B - 1, 1}, e2 = {A - 1, 1};
        E[A - 1].emplace_back(e1);
        E[B - 1].emplace_back(e2);
    }

    std::vector<long long> depth(N);
    dfs(E, E[0][0], -1, 0, depth);

    x = modpow(2, N, MOD);
    y = 0;
    for (i = 0; i < N; i++) {
        for (auto &&e : E[i]) {
            xe = e.subtree_size;
            y = (y + (modpow(2, xe, MOD) - 1) * (modpow(2, N - xe, MOD) - 1)) % MOD;
        }
    }
    y -= (N - modpow(2, N - 1, MOD));

    std::cout << y * modinv(x, MOD) % MOD << std::endl;

    return 0;
}