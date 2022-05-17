#include <iostream>
#include <vector>

int main()
{
    int n, i, j, k, kukan, tmp;

    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }
        std::vector<int> w(n);
        for (i = 0; i < n; i++) {
            std::cin >> w[i];
        }

        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        for (i = 0; i < n - 1; i++) {
            if (std::abs(w[i] - w[i + 1]) <= 1) {
                dp[i][i + 1] = 2;
            }
        }

        for (kukan = 2; kukan < n; kukan++) {
            for (i = 0; i < n - kukan; i++) {
                if (std::abs(w[i] - w[i + kukan]) <= 1 && dp[i + 1][i + kukan - 1] == kukan - 1) {
                    dp[i][i + kukan] = kukan + 1;
                } else {
                    tmp = 0;
                    for (k = i + 1; k <= i + kukan; k++) {
                        if (tmp < dp[i][k - 1] + dp[k][i + kukan]) {
                            tmp = dp[i][k - 1] + dp[k][i + kukan];
                        }
                    }
                    dp[i][i + kukan] = tmp;
                }
            }
        }

        std::cout << dp[0][n - 1] << std::endl;
    }

    return 0;
}