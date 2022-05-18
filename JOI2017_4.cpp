#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, M, i, j, d, pos;
    std::cin >> N >> M;
    std::vector<int> doll(N), sum(M);
    std::vector<std::vector<int>> accum(M, std::vector<int>(N));
    for (i = 0; i < N; i++) {
        std::cin >> d;
        doll[i] = d - 1;
        sum[doll[i]]++;
        for (j = 0; j < M; j++) {
            if (i >= 1) {
                if (j == doll[i]) {
                    accum[j][i] = accum[j][i - 1] + 1;
                } else {
                    accum[j][i] = accum[j][i - 1];
                }
            } else {
                if (j == doll[i]) {
                    accum[j][i] = 1;
                }
            }
        }
    }

    std::vector<int> dp(1 << M, 1 << 29);
    dp[0] = 0;

    for (i = 0; i < (1 << M) - 1; i++) {
        pos = 0;
        for (j = 0; j < M; j++) {
            if (i & (1 << j)) {
                pos += sum[j];
            }
        }

        for (j = 0; j < M; j++) {
            if (i & (1 << j)) {
                continue;
            }
            dp[i + (1 << j)] = std::min(dp[i + (1 << j)], dp[i] + sum[j] - (accum[j][pos + sum[j] - 1] - accum[j][pos - 1]));
        }
    }

    std::cout << dp[(1 << M) - 1] << std::endl;
    
    return 0;
}