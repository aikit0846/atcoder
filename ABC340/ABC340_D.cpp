// AC

#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int dest;
    long long cost;
};


struct Node {
    int id;
    long long cost;
};

int main()
{
    int i, j, N;
    cin >> N;
    vector<long long> A(N - 1), B(N - 1);
    vector<int> X(N - 1);
    vector<vector<Edge>> edgeVec(N - 1);
    for (i = 0; i < N - 1; i++) {
        cin >> A[i] >> B[i] >> X[i];
        
        Edge e1 = {i + 1, A[i]};
        Edge e2 = {X[i] - 1, B[i]};
        edgeVec[i].emplace_back(e1);
        edgeVec[i].emplace_back(e2);
    }

    vector<Node> nodeVec(N);
    Node node = {0, 0};
    nodeVec[0] = node;
    for (i = 1; i < N; i++) {
        Node node = {i, 1000000000000000};
        nodeVec[i] = node;
    }
    auto cmpNode = [](Node n1, Node n2) {
        return n1.cost > n2.cost;
    };

    priority_queue<Node, std::vector<Node>, decltype(cmpNode)> que{cmpNode};
    int origin = 0;
    que.push(nodeVec[origin]);

    while (!que.empty()) {
        Node now = que.top();
        int nowId = now.id;
        long long nowCost = now.cost;
        que.pop();

        if (nowId == N - 1) {
            break;
        }

        for (auto &&edge : edgeVec[nowId]) {
            int nextId = edge.dest;

            if (nodeVec[nextId].cost > nowCost + edge.cost) {
                nodeVec[nextId].cost = nowCost + edge.cost;
                que.push(nodeVec[nextId]);
            }
        }
    }

    cout << nodeVec[N - 1].cost << endl;

    return 0;
}