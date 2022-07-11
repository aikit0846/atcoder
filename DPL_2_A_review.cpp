#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int V, E, i, j, k, l, s, t, d, div, ans;
    std::cin >> V >> E;
    std::vector<std::vector<int>> G(V, std::vector<int>(V, -1));
    std::vector<int> bit(V);
    for (i = 0; i < E; i++) {
        std::cin >> s >> t >> d;
        G[s][t] = d;
    }

    ans = 1e9;
    for (l = 0; l < V; l++) {
        std::vector<std::vector<int>> dp(1 << V, std::vector<int>(V, 1e9));

        for (i = 0; i < V; i++) {
            if (G[l][i] != -1) {
                dp[1 << i][i] = G[l][i];
            }
        }

        for (i = 0; i < 1 << V; i++) {
            for (j = 0; j < V; j++) {
                div = 1 << j;
                bit[j] = (i / div) % 2;
            }

            for (j = 0; j < V; j++) {
                if (!bit[j]) {
                    continue;
                }
                for (k = 0; k < V; k++) {
                    if (bit[k] && k != j && G[k][j] != -1) {
                        dp[i][j] = std::min(dp[i][j], dp[i & ~(1 << j)][k] + G[k][j]);
                    }
                }
            }
        }

        ans = std::min(ans, dp[(1 << V) - 1][l]);
    }

    if (ans == 1e9) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << ans << std::endl;
    }

    return 0;
}