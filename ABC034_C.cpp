#include <iostream>
#include <algorithm>

const long long MOD = 1000000007;


long long modinv(long long a)
{
    long long b = MOD, u = 1, v = 0, t;

    while (b) {
        t = a / b;
        a -= t * b;
        u -= t * v;
        std::swap(a, b);
        std::swap(u, v);
    }

    u %= MOD;
    u = u < 0 ? u + MOD : u;

    return u;
}


int main()
{
    long long W, H, ans, deno, nume, i;
    std::cin >> W >> H;
    W--;
    H--;

    ans = 1;
    for (i = std::min(W, H) + 1; i <= W + H; i++) {
        ans = ans * i % MOD;
    }
    for (i = 1; i <= W + H - std::min(W, H); i++) {
        ans = ans * modinv(i) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}