#include <iostream>
#include <vector>
#include <string>
#include <numeric>

int main()
{
    int N, i, j, k;
    std::string S;
    std::cin >> N;
    std::cin >> S;

    std::vector<std::vector<int>> dp(N, std::vector<int>(1 << 3));

    for (j = 0; j < 1 << 3; j++) {
        if (S[0] == 'J') {
            if (j % 2 == 1) {
                dp[0][j] = 1;
            }
        } else if (S[0] == 'O') {
            if (j % 2 == 1 && (j / 2) % 2 == 1) {
                dp[0][j] = 1;
            }
        } else {
            if (j % 2 == 1 && (j / 4) % 2 == 1) {
                dp[0][j] = 1;
            }
        }
    }

    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < 1 << 3; j++) {
            for (k = 0; k < 1 << 3; k++) {
                if (S[i + 1] == 'J') {
                    if (k % 2 == 1 && (j & k) != 0) {
                        dp[i + 1][k] += dp[i][j];
                        dp[i + 1][k] %= 10007;
                    }
                } else if (S[i + 1] == 'O') {
                    if ((k / 2) % 2 == 1 && (j & k) != 0) {
                        dp[i + 1][k] += dp[i][j];
                        dp[i + 1][k] %= 10007;
                    }
                } else {
                    if ((k / 4) % 2 == 1 && (j & k) != 0) {
                        dp[i + 1][k] += dp[i][j];
                        dp[i + 1][k] %= 10007;
                    }
                }
            }
        }
    }

    std::cout << std::accumulate(dp[N - 1].begin(), dp[N - 1].end(), 0) % 10007 << std::endl;

    return 0;
}