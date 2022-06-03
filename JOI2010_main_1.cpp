#include <iostream>
#include <vector>
#include <algorithm>

const long long MOD = 1e5;

int main()
{
    long long n, m, i, j, a, ans;
    std::cin >> n >> m;
    std::vector<long long> s(n - 1), accum(n);
    for (i = 0; i < n - 1; i++) {
        std::cin >> s[i];
        accum[i + 1] = accum[i] + s[i];
    }

    ans = 0;
    j = 0;
    for (i = 0; i < m; i++) {
        std::cin >> a;
        ans = (ans + std::abs(accum[j + a] - accum[j])) % MOD;
        j += a;
    }

    std::cout << ans % MOD << std::endl;

    return 0;
}