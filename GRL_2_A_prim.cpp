#include <iostream>
#include <vector>
#include <queue>

struct Edge
{
    int t;
    int w;
};

int main()
{
    int V, E, i, s, t, w, ans;
    std::cin >> V >> E;
    std::vector<std::vector<Edge>> nlist(V);
    for (i = 0; i < E; i++) {
        std::cin >> s >> t >> w;
        Edge e1 = {t, w}, e2 = {s, w};
        nlist[s].emplace_back(e1);
        nlist[t].emplace_back(e2);
    }

    auto cmp = [](Edge e1, Edge e2) {
        return e1.w > e2.w;
    };
    std::vector<bool> done(V, false);
    std::priority_queue<Edge, std::vector<Edge>, decltype(cmp)> pq{cmp};

    done[0] = true;
    ans = 0;
    for (auto &&ne : nlist[0]) {
        pq.push(ne);
    }
    while (!pq.empty()) {
        Edge mine = pq.top();
        pq.pop();
        if (!done[mine.t]) {
            done[mine.t] = true;
            ans += mine.w;
        }

        for (auto &&ne : nlist[mine.t]) {
            if (!done[ne.t]) {
                pq.push(ne);
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}