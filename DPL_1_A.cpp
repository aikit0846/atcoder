#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, m, i, j;
    std::cin >> n >> m;
    std::vector<int> c(m);
    for (i = 0; i < m; i++) {
        std::cin >> c[i];
    }

    std::vector<std::vector<int>> dp(m, std::vector<int>(n + 1));
    for (j = 1; j < n + 1; j++) {
        dp[0][j] = j;
    }
    for (i = 1; i < m; i++) {
        for (j = 0; j < n + 1; j++) {
            if (j >= c[i]) {
                dp[i][j] = std::min({dp[i - 1][j], dp[i - 1][j - c[i]] + 1, dp[i][j - c[i]] + 1});
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    std::cout << dp[m - 1][n] << std::endl;

    return 0;
}