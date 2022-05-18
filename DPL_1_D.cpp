#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, i, len;
    std::cin >> n;
    std::vector<int> A(n);
    for (i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    std::vector<int> dp(n, 1e9 + 1);
    
    dp[0] = A[0];

    len = 0;
    for (i = 1; i < n; i++) {
        if (dp[len] < A[i]) {
            dp[++len] = A[i];
        } else {
            auto itr = std::lower_bound(dp.begin(), dp.end(), A[i]);
            *itr = A[i];
        }
    }

    std::cout << len + 1 << std::endl;

    return 0;
}