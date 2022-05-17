#include <iostream>
#include <vector>

int main()
{
    int N, i, j;
    std::cin >> N;
    std::vector<int> I(N);
    for (i = 0; i < N; i++) {
        std::cin >> I[i];
    }

    std::vector<std::vector<long long>> dp(N - 1, std::vector<long long>(21, 0));
    dp[0][I[0]] = 1;
    for (i = 1; i < N - 1; i++) {
        for (j = 0; j < 21; j++) {
            if (j >= I[i] && j + I[i] < 21) {
                dp[i][j] = dp[i - 1][j - I[i]] + dp[i - 1][j + I[i]];
            } else if (j >= I[i] && j + I[i] >= 21) {
                dp[i][j] = dp[i - 1][j - I[i]];
            } else {
                dp[i][j] = dp[i - 1][j + I[i]];
            }
        }
    }

    std::cout << dp[N - 2][I[N - 1]] << std::endl;

    return 0;
}