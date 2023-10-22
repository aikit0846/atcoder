#include <iostream>
#include <vector>

int main()
{
    int n, i;
    std::cin >> n;
    std::vector<int> dp(n + 1);

    dp[0] = 1;
    dp[1] = 1;
    for (i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    std::cout << dp[n] << std::endl;

    return 0;
}