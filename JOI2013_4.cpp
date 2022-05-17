#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int D, N, i, j, k, tmp;
    std::cin >> D >> N;
    std::vector<int> T(D);
    for (i = 0; i < D; i++) {
        std::cin >> T[i];
    }
    std::vector<int> A(N), B(N), C(N);
    for (i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i] >> C[i];
    }

    std::vector<std::vector<int>> dp(D, std::vector<int>(N, -(1 << 29)));

    for (j = 0; j < N; j++) {
        if (A[j] <= T[0] && T[0] <= B[j]) {
            dp[0][j] = 0;
        }
    }

    for (i = 1; i < D; i++) {
        for (j = 0; j < N; j++) {
            if (A[j] <= T[i] && T[i] <= B[j]) {
                tmp = 0;
                for (k = 0; k < N; k++) {
                    if (dp[i - 1][k] + std::abs(C[k] - C[j]) > tmp) {
                        tmp = dp[i - 1][k] + std::abs(C[k] - C[j]);
                    }
                }
                dp[i][j] = tmp;
            }
        }
    }

    std::cout << *std::max_element(dp[D - 1].begin(), dp[D - 1].end()) << std::endl;

    return 0;
}