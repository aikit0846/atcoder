#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, W, i, j;
    std::cin >> N >> W;
    std::vector<int> v(N), w(N);
    for (i = 0; i < N; i++) {
        std::cin >> v[i] >> w[i];
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1));
    for (i = 1; i < N + 1; i++) {
        for (j = 0; j < W + 1; j++) {
            if (j >= w[i - 1]) {
                dp[i][j] = std::max({dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1], dp[i][j - w[i - 1]] + v[i - 1]});
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    std::cout << dp[N][W] << std::endl;

    return 0;
}