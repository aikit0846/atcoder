#include <iostream>
#include <vector>
#include <algorithm>


int V, E;
std::vector<std::vector<int>> dp(1 << 20, std::vector<int>(20, 1 << 29)), nlist(20, std::vector<int>(20, -1));

int rec(int bit, int v, int s)
{
    if (dp[bit][v] != (1 << 29)) {
        return dp[bit][v];
    }

    if (bit == (1 << v)) {
        if (nlist[s][v] != -1) {
            dp[bit][v] = nlist[s][v];
            return dp[bit][v];
        }
    }

    int res = 1 << 29;
    int prev_bit = bit & ~(1 << v);

    for (int u = 0; u < V; u++) {
        if (!(prev_bit & (1 << u)) || nlist[u][v] == -1) {
            continue;
        }

        if (res > rec(prev_bit, u, s) + nlist[u][v]) {
            res = rec(prev_bit, u, s) + nlist[u][v];
        }
    }

    dp[bit][v] = res;
    return res;
}

int main()
{
    int i, j, k, s, d, w, ans, tmp;
    std::cin >> V >> E;
    for (i = 0; i < E; i++) {
        std::cin >> s >> d >> w;
        nlist[s][d] = w;
    }

    ans = 1 << 29;
    for (i = 0; i < V; i++) {
        for (j = 0; j < 1 << 20; j++) {
            for (k = 0; k < 20; k++) {
                dp[j][k] = 1 << 29;
            }
        }

        tmp = rec((1 << V) - 1, i, i);
        if (ans > tmp) {
            ans = tmp;
            // std::cout << i << " " << ans << " " << dp[5][0] << std::endl;
        }
    }

    std::cout << ((ans == 1 << 29) ? -1 : ans) << std::endl;

    return 0;
}