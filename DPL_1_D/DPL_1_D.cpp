#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    int n, i, idx;
    std::cin >> n;
    std::vector<int> a(n);
    for (i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> dp(n, 1 << 30);
    dp[0] = a[0];
    for (i = 1; i < n; i++) {
        auto iter = std::lower_bound(dp.begin(), dp.end(), a[i]);
        idx = (int)(iter - dp.begin());
        dp[idx] = a[i];
    }

    auto ansIter = std::lower_bound(dp.begin(), dp.end(), 1 << 30);
    std::cout << (int)(ansIter - dp.begin()) << std::endl;

    return 0;
}