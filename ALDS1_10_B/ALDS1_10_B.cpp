#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    int n, i, j, len;
    std::cin >> n;
    if (n <= 1) {
        std::cout << 0 << std::endl;
        return 0;
    }
    std::vector<int> dim1(n), dim2(n);
    for (i = 0; i < n; i++) {
        std::cin >> dim1[i] >> dim2[i];
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(n + 1, 1 << 29));
    for (i = 0; i < n - 1; i++) {
        dp[i][i + 1] = 0;
        dp[i][i + 2] = dim1[i] * dim1[i + 1] * dim2[i + 1];
    }

    for (len = 3; len <= n; len++) {
        for (i = 0; i < n + 1 - len; i++) {
            dp[i][i + len] = std::min({
                dp[i][i + len],
                dp[i][i + len - 1] + dim1[i] * dim1[i + len - 1] * dim2[i + len - 1],
                dp[i + 1][i + len] + dim1[i] * dim2[i] * dim2[i + len - 1]
            });
            for (j = 2; j < len - 1; j++) {
                dp[i][i + len] = std::min(dp[i][i + len], dp[i][i + j] + dp[i + j][i + len] + dim1[i] * dim1[i + j] * dim2[i + len - 1]);
            }
        }
    }

    std::cout << dp[0][n] << std::endl;
}