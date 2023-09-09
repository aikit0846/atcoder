#include <iostream>
#include <stack>
#include <vector>

int main()
{
    int n, i, j, u, k, tmp, now, next, time, num_next;
    std::cin >> n;
    std::vector<std::vector<int>> l(n, std::vector<int>(n, -1));
    for (i = 0; i < n; i++) {
        std::cin >> u >> k;
        std::vector<int> tmp_l(k);
        for (j = 0; j < k; j++) {
            std::cin >> tmp;
            l[u - 1][j] = tmp - 1;
        }
    }

    std::stack<int> s;
    std::vector<int> d(n, -1), f(n, -1), parent(n, -1);
    bool done;
    time = 0;
    s.push(0);
    while (!s.empty()) {
        now = s.top();
        s.pop();
        if (d[now] != -1) {
            if (s.empty()) {
                for (i = n - 1; i >= 0; i--) {
                    if (d[i] == -1) {
                        s.push(i);
                    }
                }
            }
            continue;
        }

        d[now] = ++time;
        num_next = 0;
        for (i = n - 1; i >= 0; i--) {
            next = l[now][i];
            if (next == -1) {
                continue;
            }

            if (d[next] == -1) {
                parent[next] = now;
                num_next++;
                s.push(next);
            }
        }

        if (num_next == 0) {
            if (f[now] == -1) {
                f[now] = ++time;
            }
            while (true) {
                if (parent[now] == -1) {
                    break;
                }
                done = true;
                for (auto &&child : l[parent[now]]) {
                    if (parent[child] != parent[now]) {
                        continue;
                    }
                    if (f[child] == -1) {
                        done = false;
                        break;
                    }
                }
                if (!done) {
                    break;
                }
                if (f[parent[now]] == -1) {
                    f[parent[now]] = ++time;
                }
                now = parent[now];
            }
        }

        if (s.empty()) {
            for (i = n - 1; i >= 0; i--) {
                if (d[i] == -1) {
                    s.push(i);
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        std::cout << i + 1 << " " << d[i] << " " << f[i] << std::endl;
    }

    return 0;
}