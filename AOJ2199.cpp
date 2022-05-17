#include <iostream>
#include <vector>
#include <algorithm>

long long add(long long a, long long b) {
    if (a + b > 255) {
        return 255;
    } else if (a + b < 0) {
        return 0;
    } else {
        return a + b;
    }
}

int main()
{
    long long N, M, i, j, k, dif;

    while (true) {
        std::cin >> N >> M;
        if (N == 0 && M == 0) {
            break;
        }
        std::vector<long long> C(M), x(N + 1);
        for (i = 0; i < M; i++) {
            std::cin >> C[i];
        }
        for (i = 1; i < N + 1; i++) {
            std::cin >> x[i];
        }

        std::vector<std::vector<long long>> dp(N + 1, std::vector<long long>(256, 1e18));
        dp[0][128] = 0;

        for (i = 0; i < N; i++) {
            for (j = 0; j < 256; j++) {
                for (k = 0; k < M; k++) {
                    dif = (x[i + 1] - add(j, C[k])) * (x[i + 1] - add(j, C[k]));
                    if (dp[i][j] + dif < dp[i + 1][add(j, C[k])]) {
                        dp[i + 1][add(j, C[k])] = dp[i][j] + dif;
                    }
                }
            }
        }

        std::cout << *std::min_element(dp[N].begin(), dp[N].end()) << std::endl;
    }

    return 0;
}