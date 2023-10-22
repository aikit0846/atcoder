#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int i, j, n, m;
    std::cin >> n >> m;
    std::vector<int> dp(n + 1, 1 << 29), c(n);
    for (i = 0; i < m; i++) {
        std::cin >> c[i];
        dp[c[i]] = 1;
    }

    dp[0] = 0;
    for (i = 1; i < n + 1; i++) {
        for (j = 0; j < m; j++) {
            if (i >= c[j]) {
                dp[i] = std::min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }

    std::cout << dp[n] << std::endl;

    return 0;
}