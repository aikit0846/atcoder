#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    int n, i, j, k, len;

    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }
        std::vector<int> w(n);
        for (i = 0; i < n; i++) {
            std::cin >> w[i];
        }

        std::vector<std::vector<int>> dp(n, std::vector<int>(n));
        for (i = 0; i < n - 1; i++) {
            if (std::abs(w[i] - w[i + 1]) <= 1) {
                dp[i][i + 1] = 2;
            }
        }
        for (len = 3; len <= n; len++) {
            for (i = 0; i <= n - len; i++) {
                if (std::abs(w[i] - w[i + len - 1]) <= 1 && dp[i + 1][i + len - 2] == len - 2) {
                    dp[i][i + len - 1] = len;
                } else {
                    for (j = i; j <= i + len - 2; j++) {
                        dp[i][i + len - 1] = std::max(dp[i][i + len - 1], dp[i][j] + dp[j + 1][i + len - 1]);
                    }
                }
            }
        }

        std::cout << dp[0][n - 1] << std::endl;
    }

    return 0;
}