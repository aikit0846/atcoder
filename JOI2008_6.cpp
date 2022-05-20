#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int main()
{
    int n, k, i, info, a, b, c, d, e, now, next, fare;
    std::cin >> n >> k;
    std::vector<std::vector<std::tuple<int, int>>> n_list(n);

    for (i = 0; i < k; i++) {
        std::cin >> info;
        if (info) {
            std::cin >> c >> d >> e;
            n_list[c - 1].emplace_back(std::tuple<int, int>(d - 1, e));
            n_list[d - 1].emplace_back(std::tuple<int, int>(c - 1, e));
        } else {
            std::cin >> a >> b;
            std::vector<int> sp(n, 1e9);
            std::priority_queue<int> q;

            sp[a - 1] = 0;
            q.push(a - 1);
            while (q.size() > 0) {
                now = q.top();
                q.pop();

                for (auto &&nt : n_list[now]) {
                    next = std::get<0>(nt);
                    fare = std::get<1>(nt);
                    if (sp[now] + fare < sp[next]) {
                        sp[next] = sp[now] + fare;
                        q.push(next);
                    }
                }
            }

            std::cout << ((sp[b - 1] != 1e9) ? sp[b - 1] : -1) << std::endl;
        }
    }

    return 0;
}