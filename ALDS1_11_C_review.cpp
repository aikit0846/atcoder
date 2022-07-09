#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int main()
{
    int n, i, j, u, k, v, now;
    std::cin >> n;
    std::vector<std::vector<int>> nlist(n);
    for (i = 0; i < n; i++) {
        std::cin >> u >> k;
        for (j = 0; j < k; j++) {
            std::cin >> v;
            nlist[u - 1].emplace_back(v - 1);
        }
    }

    std::vector<int> sd(n, -1);
    std::vector<bool> done(n, false);
    std::queue<int> q;

    sd[0] = 0;
    done[0] = true;
    q.push(0);
    while (!q.empty()) {
        now = q.front();
        q.pop();

        for (auto &&nn : nlist[now]) {
            if (!done[nn]) {
                sd[nn] = sd[now] + 1;
                done[nn] = true;
                q.push(nn);
            }
        }
    }

    for (i = 0; i < n; i++) {
        std::cout << i + 1 << " " << sd[i] << std::endl;
    }

    return 0;
}