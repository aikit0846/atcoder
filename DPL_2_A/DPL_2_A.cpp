#include <iostream>
#include <vector>
#include <algorithm>


void rec(std::vector<std::vector<std::vector<int>>> &dp, std::vector<std::vector<int>> d, int bit, int v, int V, int goal)
{
    if (dp[bit][v][goal] != -1) {
        return;
    }

    if (bit == (1 << v)) {
        if (d[goal][v] == -1) {
            dp[bit][v][goal] = -1;
            return;
        }
        dp[bit][v][goal] = d[goal][v];
        return;
    }

    int prev_bit = bit & ~(1 << v);
    for (int u = 0; u < V; u++) {
        if ((prev_bit != 0 && !(prev_bit & (1 << u))) || d[u][v] == -1) {
            continue;
        }

        rec(dp, d, prev_bit, u, V, goal);
        if (dp[prev_bit][u][goal] == -1) {
            continue;
        }
        dp[bit][v][goal] = ((dp[bit][v][goal] == -1) ? (dp[prev_bit][u][goal] + d[u][v]) : std::min(dp[bit][v][goal], dp[prev_bit][u][goal] + d[u][v]));
    }

    return;
}


int main()
{
    int V, E, e, s, t, start, goal, ans;
    std::cin >> V >> E;
    std::vector<std::vector<int>> d(V, std::vector<int>(V, -1));
    for (e = 0; e < E; e++) {
        std::cin >> s >> t;
        std::cin >> d[s][t];
    }

    std::vector<std::vector<std::vector<int>>> dp(1 << V, std::vector<std::vector<int>>(V, std::vector<int>(V, -1)));
    ans = -1;
    
    // 閉路なので、1つの開始点・終了点のみ考えればよい
    rec(dp, d, (1 << V) - 1, 0, V, 0);
    std::cout << dp[(1 << V) - 1][0][0] << std::endl;

    return 0;
}