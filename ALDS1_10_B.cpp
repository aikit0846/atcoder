#include <iostream>
#include <vector>

int main()
{
    int n, i, j, k, tmp, kukan;
    std::cin >> n;
    std::vector<int> r(n), c(n);
    for (i = 0; i < n; i++) {
        std::cin >> r[i] >> c[i];
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    
    for (i = 0; i < n - 1; i++) {
        dp[i][i] = 0;
        dp[i][i + 1] = r[i] * c[i] * c[i + 1];
    }
    dp[n - 1][n - 1] = 0;

    for (kukan = 2; kukan < n; kukan++) {
        for (i = 0; i < n - kukan; i++) {
            tmp = 1 << 29;
            for (k = i + 1; k <= i + kukan; k++) {
                if (tmp > dp[i][k - 1] + dp[k][i + kukan] + r[i] * c[k - 1] * c[i + kukan]) {
                    tmp = dp[i][k - 1] + dp[k][i + kukan] + r[i] * c[k - 1] * c[i + kukan];
                }
            }
            dp[i][i + kukan] = tmp;
        }
    }

    std::cout << dp[0][n - 1] << std::endl;

    return 0; 
}