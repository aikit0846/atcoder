#include <iostream>
#include <vector>
#include <algorithm>

class NodeTime {
    public:
    int id;
    int time;
};

int main()
{
    int N, M, i, j, k, a, b, t;
    std::cin >> N >> M;
    std::vector<std::vector<NodeTime>> nlist(N);
    for (i = 0; i < M; i++) {
        std::cin >> a >> b >> t;
        NodeTime nt1 = {b - 1, t}, nt2 = {a - 1, t};
        nlist[a - 1].emplace_back(nt1);
        nlist[b - 1].emplace_back(nt2);
    }

    std::vector<std::vector<int>> dp(N, std::vector<int>(N, 1e9));

    for (i = 0; i < N; i++) {
        for (auto &&nt : nlist[i]) {
            dp[i][nt.id] = nt.time;
        }
        dp[i][i] = 0;
    }

    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    std::vector<int> bus_max(N, 1e9);
    for (i = 0; i < N; i++) {
        bus_max[i] = *std::max_element(dp[i].begin(), dp[i].end()); 
    }

    std::cout << *std::min_element(bus_max.begin(), bus_max.end()) << std::endl;

    return 0;
}