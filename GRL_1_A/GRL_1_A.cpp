#include <iostream>
#include <vector>
#include <queue>


struct Edge {
    int t;
    int d;
};


struct Node {
    int v;
    int sp;
};


int main()
{
    int V, E, s, t, d, r, v, u, e;
    std::cin >> V >> E >> r;
    std::vector<std::vector<Edge>> edge(V);
    for (e = 0; e < E; e++) {
        std::cin >> s >> t >> d;
        Edge tmp = {t, d};
        edge[s].emplace_back(tmp);
    }

    auto compare = [](Node v1, Node v2) {
        return v1.sp > v2.sp;
    };

    std::priority_queue<Node, std::vector<Node>, decltype(compare)> que{compare};
    std::vector<Node> node(V);
    for (v = 0; v < V; v++) {
        Node tmp = {v, ((v == r) ? 0 : (1 << 30))};
        node[v] = tmp;
    }

    que.push(node[r]);
    std::vector<bool> isConfirmed(V, false);
    while (!que.empty()) {
        Node now = que.top();
        que.pop();
        isConfirmed[now.v] = true;

        for (auto &&nextEdge : edge[now.v]) {
            Node &next = node[nextEdge.t];
            if (!isConfirmed[next.v] && next.sp > now.sp + nextEdge.d) {
                next.sp = now.sp + nextEdge.d;
                que.push(next);
            }
        }
    }

    for (v = 0; v < V; v++) {
        if (node[v].sp == (1 << 30)) {
            std::cout << "INF" << std::endl;
        } else {
            std::cout << node[v].sp << std::endl;
        }
        
    }

    return 0;
}