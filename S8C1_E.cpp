#include <iostream>
#include <vector>

const long long MOD = 1000000007;


long long modpow(long long a, long long n)
{
    long long res = 1;

    while (n > 0) {
        if (n & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        n >>= 1;
    }

    return res;
}


int main()
{
    long long N, Q, i, j, ans, c, prev;
    std::cin >> N >> Q;
    std::vector<long long> a(N), len(N - 1), accum(N);
    for (i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    for (i = 0; i < N - 1; i++) {
        len[i] = modpow(a[i], a[i + 1]);
        accum[i + 1] = accum[i] + len[i];
    }

    ans = 0;
    std::cin >> c;
    ans = (ans + (accum[c - 1] - accum[0])) % MOD;
    prev = c - 1;
    for (i = 1; i < Q; i++) {
        std::cin >> c;
        ans = (ans + std::abs(accum[c - 1] - accum[prev])) % MOD;
        prev = c - 1;
    }
    ans = (ans + (accum[prev] - accum[0])) % MOD;

    std::cout << ans << std::endl;

    return 0;
}