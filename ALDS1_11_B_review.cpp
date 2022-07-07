#include <iostream>
#include <vector>
#include <algorithm>

int dfs(std::vector<std::vector<int>> nlist, std::vector<int> &seen, std::vector<int> &done, int now, int time, int n)
{
    int end_time = time + 1, i;

    seen[now] = time;
    for (auto &&nn : nlist[now]) {
        if (seen[nn] == -1) {
            end_time = std::max(end_time, dfs(nlist, seen, done, nn, end_time, n));
        }
    }
    done[now] = end_time;

    return end_time + 1;
}

int main()
{
    int n, i, j, u, k, v, now, time, end_time;
    std::cin >> n;
    std::vector<std::vector<int>> nlist(n);
    for (i = 0; i < n; i++) {
        std::cin >> u >> k;
        for (j = 0; j < k; j++) {
            std::cin >> v;
            nlist[u - 1].emplace_back(v - 1);
        }
    }
    std::vector<int> seen(n, -1), done(n, -1);

    end_time = dfs(nlist, seen, done, 0, 1, n);
    auto it = std::find(seen.begin(), seen.end(), -1);
    while (it != seen.end()) {
        dfs(nlist, seen, done, it - seen.begin(), end_time, n);
        it = std::find(seen.begin(), seen.end(), -1);
    }

    for (i = 0; i < n; i++) {
        std::cout << i + 1 << " " << seen[i] << " " << done[i] << std::endl;
    }

    return 0;
}