#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    long long V, E, i, j, k, s, t, d;
    std::cin >> V >> E;
    std::vector<std::vector<long long>> dp(V, std::vector<long long>(V, 1e18));
    for (i = 0; i < E; i++) {
        std::cin >> s >> t >> d;
        dp[s][t] = d;
    }
    for (i = 0; i < V; i++) {
        dp[i][i] = 0;
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dp[i][k] == 1e18 || dp[k][j] == 1e18) {
                    dp[i][j] = dp[i][j];
                } else {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }

    for (i = 0; i < V; i++) {
        if (dp[i][i] < 0) {
            std::cout << "NEGATIVE CYCLE" << std::endl;
            return 0;
        }
    }

    for (i = 0; i < V; i++) {
        for (j = 0; j < V - 1; j++) {
            if (dp[i][j] >= 1e18) {
                std::cout << "INF ";
            } else {
                std::cout << dp[i][j] << " ";
            }
        }
        if (dp[i][V - 1] >= 1e18) {
            std::cout << "INF" << std::endl;
        } else {
            std::cout << dp[i][V - 1] << std::endl;
        }
    }

    return 0;
}