#include <iostream>
#include <vector>

int main()
{
    int n, i;
    std::cin >> n;

    std::vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (i = 2; i < n + 1; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    std::cout << dp[n] << std::endl;

    return 0;
}