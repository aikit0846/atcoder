#include <iostream>
#include <vector>
#include <stdio.h>

double memo(std::vector<std::vector<std::vector<double>>> &dp, std::vector<std::vector<std::vector<bool>>> &flag, int idx1, int idx2, int idx3, int N)
{
    double multi;
    double Nd = static_cast<double>(N);

    if (flag[idx1][idx2][idx3]) {
        return dp[idx1][idx2][idx3];
    }

    flag[idx1][idx2][idx3] = true;
    multi = 1 / (1 - (N - idx1 - idx2 - idx3) / Nd);
    
    dp[idx1][idx2][idx3] = multi;
    if (idx1) {
        dp[idx1][idx2][idx3] += memo(dp, flag, idx1 - 1, idx2, idx3, N) * (idx1 / Nd) * multi;
    }
    if (idx2) {
        dp[idx1][idx2][idx3] += memo(dp, flag, idx1 + 1, idx2 - 1, idx3, N) * (idx2 / Nd) * multi;
    }
    if (idx3) {
        dp[idx1][idx2][idx3] += memo(dp, flag, idx1, idx2 + 1, idx3 - 1, N) * (idx3 / Nd) * multi;
    }

    return dp[idx1][idx2][idx3];
}

int main()
{
    int N, i, j, a;
    std::cin >> N;
    std::vector<int> num(4);
    for (i = 0; i < N; i++) {
        std::cin >> a;
        num[a]++;
    }

    std::vector<std::vector<std::vector<double>>> dp(N + 1, std::vector<std::vector<double>>(N + 1, std::vector<double>(N + 1)));
    std::vector<std::vector<std::vector<bool>>> flag(N + 1, std::vector<std::vector<bool>>(N + 1, std::vector<bool>(N + 1, false)));
    dp[0][0][0] = 0;
    flag[0][0][0] = true;
    dp[0][1][0] = 2 * N;
    flag[0][1][0] = true;
    dp[0][0][1] = 3 * N;
    flag[0][0][1] = true;
    for (i = 1; i <= N; i++) {
        dp[i][0][0] = 0;
        for (j = 1; j <= i; j++) {
            dp[i][0][0] += static_cast<double>(N) / j;
        }
        flag[i][0][0] = true;
    }

    printf("%.9f\n", memo(dp, flag, num[1], num[2], num[3], N));

    return 0;
}