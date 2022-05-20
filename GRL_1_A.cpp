#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int main()
{
    long long V, E, r, i, j, s, t, d, now, next, w;
    std::cin >> V >> E >> r;
    std::vector<std::vector<std::tuple<long long, long long>>> nlist(V);
    for (i = 0; i < E; i++) {
        std::cin >> s >> t >> d;
        nlist[s].emplace_back(std::tuple<long long, long long>(t, d));
    }

    std::priority_queue<long long> q;
    std::vector<long long> sp(V, 1e18);

    sp[r] = 0;
    q.push(r);
    while (q.size() > 0) {
        now = q.top();
        q.pop();

        for (auto &&nt : nlist[now]) {
            next = std::get<0>(nt);
            w = std::get<1>(nt);
            if (sp[now] + w < sp[next]) {
                sp[next] = sp[now] + w;
                q.push(next);
            }
        }
    }

    for (i = 0; i < V; i++) {
        if (sp[i] != 1e18) {
            std::cout << sp[i] << std::endl;
        } else {
            std::cout << "INF" << std::endl;
        }
    }

    return 0;
}