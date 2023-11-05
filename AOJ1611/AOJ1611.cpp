#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    int n, i, j, len;

    while (true) {
        std::cin >> n;
        if (!n) {
            break;
        }
        std::vector<int> w(n);
        for (i = 0; i < n; i++) {
            std::cin >> w[i];
        }

        std::vector<std::vector<int>> dp(n, std::vector<int>(n + 1, 0));
        for (i = 0; i < n - 1; i++) {
            if (-1 <= w[i] - w[i + 1] && w[i] - w[i + 1] <= 1) {
                dp[i][i + 2] = 2;
            }
        }

        for (len = 3; len <= n; len++) {
            for (i = 0; i < n - len + 1; i++) {
                if (dp[i + 1][i + len - 1] == len - 2) {
                    if (-1 <= w[i] - w[i + len - 1] && w[i] - w[i + len - 1] <= 1) {
                        dp[i][i + len] = len;
                    } else {
                        dp[i][i + len] = std::max(dp[i][i + len], len - 2);
                    }
                }

                for (j = 1; j < len; j++) {
                    dp[i][i + len] = std::max(dp[i][i + len], dp[i][i + j] + dp[i + j][i + len]);
                }
            }
        }

        std::cout << dp[0][n] << std::endl;
    }

    return 0;
}