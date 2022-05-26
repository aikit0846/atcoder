#include <iostream>
#include <vector>

int main()
{
    long long N, i, j, k, ans;
    std::cin >> N;
    std::vector<std::vector<long long>> A(N, std::vector<long long>(N)), dp(N, std::vector<long long>(N, 1e9));
    ans = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            std::cin >> A[i][j];
            dp[i][j] = A[i][j];
            if (i > j) {
                ans += A[i][j];
            }
        }
    }

    std::vector<std::vector<bool>> road(N, std::vector<bool>(N, true));
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (dp[i][j] > dp[i][k] + dp[k][j]) {
                    std::cout << -1 << std::endl;
                    return 0;
                } else if (dp[i][j] == dp[i][k] + dp[k][j]) {
                    if (k != i && k != j && road[i][j]) {
                        road[i][j] = false;
                        road[j][i] = false;
                        ans -= A[i][j];
                        // std::cout << i << " " << j << std::endl;
                    }
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}