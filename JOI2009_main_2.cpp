#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int d, n, m, i, j, ans;
    std::cin >> d;
    std::cin >> n;
    std::cin >> m;
    std::vector<int> di(n), k(m);
    for (i = 1; i < n; i++) {
        std::cin >> di[i];
    }
    for (i = 0; i < m; i++) {
        std::cin >> k[i];
    }

    std::sort(di.begin(), di.end());
    ans = 0;
    for (i = 0; i < m; i++) {
        auto itr = std::lower_bound(di.begin(), di.end(), k[i]);
        ans += std::min(std::min(std::abs(k[i] - *itr), d - std::abs(k[i] - *itr)), std::min(std::abs(k[i] - *(itr - 1)), d - std::abs(k[i] - *(itr - 1))));
    }

    std::cout << ans << std::endl;

    return 0;
}