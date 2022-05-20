#include <iostream>
#include <vector>
#include <queue>

class Node {
    public:
    long long id;
    long long money;
};

int main()
{
    long long N, K, M, S, P, Q, C, A, B, i, now, next, price, cost;
    std::cin >> N >> M >> K >> S;
    std::cin >> P >> Q;
    std::vector<int> dang(N, 0);
    std::vector<std::vector<Node>> road(N);
    for (i = 0; i < K; i++) {
        std::cin >> C;
        dang[C - 1] = 2;
    }
    for (i = 0; i < M; i++) {
        std::cin >> A >> B;
        Node d1 = {B - 1, 0};
        Node d2 = {A - 1, 0};
        road[A - 1].emplace_back(d1);
        road[B - 1].emplace_back(d2);
    }

    // 危険な町を列挙する
    for (i = 1; i < N - 1; i++) {
        if (dang[i] == 2) {
            std::vector<long long> sp(N, 1e15);
            std::queue<long long> q;

            sp[i] = 0;
            q.push(i);
            while (q.size() > 0) {
                now = q.front();
                q.pop();

                for (auto &&nv : road[now]) {
                    next = nv.id;
                    // std::cout << now << " " << next << std::endl;
                    if (sp[now] + 1 < sp[next] && sp[now] + 1 <= S) {
                        sp[next] = sp[now] + 1;
                        q.push(next);
                        if (dang[next] == 0) {
                            dang[next] = 1;
                        }
                    }
                }
            }
        }
    }

    // 道路の重みを更新する
    for (i = 0; i < N - 1; i++) {
        for (auto &&nv : road[i]) {
            next = nv.id;
            if (next == 0 || next == N - 1) {
                continue;
            }
            if (dang[next] == 2) {
                nv.money = 1e15;
            } else if (dang[next] == 1) {
                nv.money = Q;
            } else {
                nv.money = P;
            }
            // std::cout << nv.id << " " << nv.money << std::endl;
        }
    }

    // 最短経路探索
    std::vector<long long> cp(N, 1e18);
    std::priority_queue<std::vector<long long>, std::vector<std::vector<long long>>, std::greater<std::vector<long long>>> pq;

    cp[0] = 0;
    std::vector<long long> ele = {cp[0], 0};
    pq.push(ele);
    while (pq.size() > 0) {
        std::vector<long long> v = pq.top();
        pq.pop();
        now = v[1];
        cost = v[0];

        if (now == N - 1) {
            break;
        }

        for (auto &&nv : road[now]) {
            next = nv.id;
            price = nv.money;
            if (cost + price < cp[next]) {
                cp[next] = cost + price;
                std::vector<long long> ele = {cp[next], next};
                pq.push(ele);
            }
        }
    }

    std::cout << cp[N - 1] << std::endl;

    return 0;
}