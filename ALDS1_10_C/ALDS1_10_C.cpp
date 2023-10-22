#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    int q, i, j, k, N, M;
    std::string X, Y;
    std::cin >> q;

    for (k = 0; k < q; k++) {
        std::cin >> X;
        std::cin >> Y;
        N = (int)X.size();
        M = (int)Y.size();
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1));

        for (i = 1; i < N + 1; i++) {
            for (j = 0; j < M + 1; j++) {
                if (X[i - 1] == Y[j - 1]) {
                    dp[i][j] = std::max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + 1});
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        std::cout << dp[N][M] << std::endl;
    }

    return 0;
}