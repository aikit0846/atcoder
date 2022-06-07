#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, i, ele, ans, tmp;
    std::cin >> N;
    std::vector<int> light(N), cluster;
    for (i = 0; i < N; i++) {
        std::cin >> light[i];
    }

    ele = 0;
    for (i = 0; i < N - 1; i++) {
        ele++;
        if (light[i] == light[i + 1]) {
            cluster.emplace_back(ele);
            ele = 0;
        }
    }
    if (light[N - 2] == light[N - 1]) {
        cluster.emplace_back(1);
    } else {
        cluster.emplace_back(ele + 1);
    }

    if (cluster.size() <= 3) {
        std::cout << N << std::endl;
        return 0;
    }

    ans = cluster[0] + cluster[1] + cluster[2];
    tmp = ans;
    for (i = 1; i < cluster.size() - 2; i++) {
        tmp = tmp - cluster[i - 1] + cluster[i + 2];
        ans = std::max(ans, tmp);
    }

    std::cout << ans << std::endl;

    return 0;
}