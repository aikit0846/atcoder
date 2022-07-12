#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int t;
    int d;
};

struct Node {
    int id;
    int sp;
};

int main()
{
    int V, E, r, i, s, t, d;
    std::cin >> V >> E >> r;
    std::vector<std::vector<Edge>> elist(V);
    for (i = 0; i < E; i++) {
        std::cin >> s >> t >> d;
        Edge e = {t, d};
        elist[s].emplace_back(e);
    }

    auto cmp = [](Node v1, Node v2) {
        return v1.sp > v2.sp;
    };
    std::priority_queue<Node, std::vector<Node>, decltype(cmp)> pq{cmp};
    std::vector<bool> done(V, false);
    std::vector<Node> node(V);
    for (i = 0; i < V; i++) {
        Node v = {i, static_cast<int>(1e9)};
        node[i] = v;
    }

    node[r].sp = 0;
    pq.push(node[r]);
    while (!pq.empty()) {
        Node v = pq.top();
        pq.pop();
        done[v.id] = true;

        for (auto &&e : elist[v.id]) {
            if (!done[e.t] && v.sp + e.d < node[e.t].sp) {
                node[e.t].sp = v.sp + e.d;
                pq.push(node[e.t]);
            }
        }
    }

    for (i = 0; i < V; i++) {
        if (node[i].sp == static_cast<int>(1e9)) {
            std::cout << "INF" << std::endl;
        } else {
            std::cout << node[i].sp << std::endl;
        }
    }

    return 0;
}