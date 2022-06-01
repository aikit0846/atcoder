#include <iostream>

const long long MOD = 1e9 + 7;


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


long long combination(long long n, long long r, long long m)
{
    long long res = 1, i;

    for (i = r + 1; i <= n; i++) {
        res = res * i % m;
    }

    for (i = 1; i <= n - r; i++) {
        res = res * modinv(i, m) % m;
    }

    return res;
}


int main()
{
    long long n, k;
    std::cin >> n;
    std::cin >> k;

    std::cout << combination(n + k - 1, k, MOD) << std::endl;

    return 0;
}