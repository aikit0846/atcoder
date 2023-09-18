#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int n, i, j, u, k, tmp, now, count;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (i = 0; i < n; i++) {
        std::cin >> u >> k;
        for (j = 0; j < k; j++) {
            std::cin >> tmp;
            adj[u - 1].emplace_back(tmp - 1);
        }
    }

    std::queue<int> que;
    std::vector<int> dist(n, -1);
    dist[0] = 0;
    que.push(0);
    while (!que.empty()) {
        now = que.front();
        que.pop();
        for (auto &&next : adj[now]) {
            if (dist[next] == -1) {
                dist[next] = dist[now] + 1;
                que.push(next);
            } else if (dist[next] > dist[now] + 1) {
                dist[next] = dist[now] + 1;
                que.push(next);
            }
        }
    }

    for (i = 0; i < n; i++) {
        std::cout << i + 1 << " " << dist[i] << std::endl;
    }

    return 0;
}