#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, i, ans;
    std::cin >> N;
    std::vector<int> c(N);
    for (i = 0; i < N; i++) {
        std::cin >> c[i];
    }

    std::vector<int> dp(N + 1, N + 1);

    dp[0] = 0;
    dp[1] = c[0];

    for (i = 1; i < N; i++) {
        auto itr = std::lower_bound(dp.begin(), dp.end(), c[i]);
        *itr = c[i];
    }

    auto it = std::lower_bound(dp.begin(), dp.end(), N + 1);
    ans = N - (it - dp.begin() - 1);

    std::cout << ans << std::endl;

    return 0;
}

// 要復習