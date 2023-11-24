#include <iostream>
#include <vector>
#include <queue>


struct Node {
    int idx;
    int pathLength;
};


struct Edge {
    int tIdx;
    int cost;
};


int main()
{
    int N, K, i, j;
    std::cin >> N >> K;
    std::vector<int> C(N), R(N);
    std::vector<std::vector<int>> edgeVector(N);
    std::vector<std::vector<Edge>> edgeFareVector(N);
    for (i = 0; i < N; i++) {
        std::cin >> C[i] >> R[i];
    }
    for (i = 0; i < K; i++) {
        int A, B;
        std::cin >> A >> B;
        edgeVector[B - 1].emplace_back(A - 1);
        edgeVector[A - 1].emplace_back(B - 1);
    }

    for (i = 0; i < N; i++) {
        std::queue<int> que;
        std::vector<int> isReachable(N, 1 << 29);
        que.push(i);
        isReachable[i] = 0;
        while (!que.empty()) {
            int now = que.front();
            que.pop();

            for (auto &&next : edgeVector[now]) {
                if (isReachable[now] + 1 <= R[i] && isReachable[now] + 1 < isReachable[next]) {
                    isReachable[next] = isReachable[now] + 1;
                    que.push(next);
                }
            }
        }

        for (j = 0; j < N; j++) {
            if (j != i && isReachable[j] <= R[i]) {
                Edge tmp = {j, C[i]};
                edgeFareVector[i].emplace_back(tmp);
            }
        }
    }

    auto compare = [](Node v1, Node v2) {
        return v1.pathLength > v2.pathLength;
    };
    std::priority_queue<Node, std::vector<Node>, decltype(compare)> pQue{compare};
    std::vector<bool> isConfirmed(N, false);
    std::vector<Node> nodeVector(N);
    for (i = 0; i < N; i++) {
        Node tmp = {i, ((i == 0) ? 0 : (1 << 29))};
        nodeVector[i] = tmp;
    }

    pQue.push(nodeVector[0]);
    while (!pQue.empty()) {
        Node now = pQue.top();
        if (now.idx == N - 1) {
            break;
        }
        pQue.pop();
        isConfirmed[now.idx] = true;

        for (auto &&nextEdge : edgeFareVector[now.idx]) {
            Node &next = nodeVector[nextEdge.tIdx];
            if (!isConfirmed[next.idx] && (next.pathLength > now.pathLength + nextEdge.cost)) {
                next.pathLength = now.pathLength + nextEdge.cost;
                pQue.push(next);
            }
        }
    }

    std::cout << nodeVector[N - 1].pathLength << std::endl;

    return 0;
}