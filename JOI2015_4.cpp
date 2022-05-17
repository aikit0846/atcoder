#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, M, i, j;
    std::cin >> N >> M;
    std::vector<int> D(N), C(M);
    for (i = 0; i < N; i++) {
        std::cin >> D[i];
    }
    for (i = 0; i < M; i++) {
        std::cin >> C[i];
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1, 1 << 29));
    
    for (j = 0; j < M + 1; j++) {
        dp[0][j] = 0;
    }

    for (i = 1; i < N + 1; i++) {
        for (j = i; j < M + 1; j++) {
            dp[i][j] = std::min(dp[i][j - 1], dp[i - 1][j - 1] + D[i - 1] * C[j - 1]);
            // std::cout << dp[i][j] << std::endl;
        }
    }

    std::cout << *std::min_element(dp[N].begin(), dp[N].end()) << std::endl;

    return 0;
}