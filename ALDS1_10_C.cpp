#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    int q, i, j, k, l1, l2;
    std::string s1, s2;
    std::cin >> q;

    for (k = 0; k < q; k++) {
        std::cin >> s1;
        std::cin >> s2;
        l1 = s1.size();
        l2 = s2.size();

        std::vector<std::vector<int>> dp(l1 + 1, std::vector<int>(l2 + 1));
        for (i = 1; i < l1 + 1; i++) {
            for (j = 1; j < l2 + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = std::max({dp[i - 1][j - 1] + 1, dp[i - 1][j], dp[i][j - 1]});
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        std::cout << dp[l1][l2] << std::endl;
    }

    return 0;
}