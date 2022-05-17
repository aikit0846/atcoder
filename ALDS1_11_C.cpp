#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int n, i, j, u, k, v, count, now;
    std::cin >> n;
    std::vector<std::vector<int>> nl(n);
    for (i = 0; i < n; i++) {
        std::cin >> u >> k;
        for (j = 0; j < k; j++) {
            std::cin >> v;
            nl[u - 1].emplace_back(v - 1);
        }
    }

    std::queue<int> q;
    std::vector<int> sp(n, 1 << 29);

    count = 0;
    sp[0] = 0;
    q.push(0);
    while (q.size() > 0) {
        now = q.front();
        q.pop();
        count = sp[now] + 1;

        for (auto &&nv : nl[now]) {
            if (count < sp[nv]) {
                sp[nv] = count;
                q.push(nv);
            }
        }
    }

    for (i = 0; i < n; i++) {
        std::cout << i + 1 << " " << ((sp[i] == (1 << 29)) ? -1 : sp[i]) << std::endl;
    }

    return 0;
}