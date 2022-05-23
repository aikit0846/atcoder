#include <iostream>
#include <vector>
#include <queue>

class NodeFare {
    public:
    int id;
    int fare;
};

int main()
{
    int N, K, i, j, A, B, now;
    std::cin >> N >> K;
    std::vector<int> C(N), R(N);
    for (i = 0; i < N; i++) {
        std::cin >> C[i] >> R[i];
    }
    std::vector<std::vector<int>> road(N);
    for (i = 0; i < K; i++) {
        std::cin >> A >> B;
        road[A - 1].emplace_back(B - 1);
        road[B - 1].emplace_back(A - 1);
    }

    std::vector<std::vector<NodeFare>> fare(N);
    for (i = 0; i < N; i++) {
        std::queue<int> q;
        std::vector<int> sp(N, 1e9);

        sp[i] = 0;
        q.push(i);
        while (!q.empty()) {
            now = q.front();
            q.pop();

            for (auto &&next : road[now]) {
                if (sp[now] + 1 < sp[next] && sp[now] + 1 <= R[i]) {
                    sp[next] = sp[now] + 1;
                    q.push(next);
                }
            }
        }

        for (j = 0; j < N; j++) {
            if (sp[j] <= R[i] && j != i) {
                NodeFare nf = {j, C[i]};
                fare[i].emplace_back(nf);
            }
        }
    }

    std::vector<int> sc(N, 1e9);
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> pq;

    sc[0] = 0;
    std::vector<int> v = {sc[0], 0};
    pq.push(v);
    while (!pq.empty()) {
        std::vector<int> vv = pq.top();
        pq.pop();
        if (vv[1] == N - 1) {
            break;
        }

        for (auto &&nv : fare[vv[1]]) {
            if (vv[0] + nv.fare < sc[nv.id]) {
                sc[nv.id] = vv[0] + nv.fare;
                std::vector<int> v = {sc[nv.id], nv.id};
                pq.push(v);
            }
        }
    }

    std::cout << sc[N - 1] << std::endl;

    return 0;
}