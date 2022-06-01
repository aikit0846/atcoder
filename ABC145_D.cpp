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
    long long i, res = 1;

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
    long long X, Y, i;
    std::cin >> X >> Y;

    if ((2 * X - Y) % 3 || (-X + 2 * Y) % 3 || 2 * X - Y < 0 || -X + 2 * Y < 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << combination((X + Y) / 3, (-X + 2 * Y) / 3, MOD) << std::endl;
    }

    return 0;
}