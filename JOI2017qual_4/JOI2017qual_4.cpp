#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    int N, M, i, j, tmp, lastIdx, toAdd;
    std::cin >> N >> M;
    std::vector<int> initial(N), count(M, 0);
    std::vector<std::vector<int>> cumSum(M, std::vector<int>(N + 1, 0));
    for (i = 0; i < N; i++) {
        std::cin >> tmp;
        initial[i] = tmp - 1;
        count[initial[i]]++;

        for (j = 0; j < M; j++) {
            if (j == initial[i]) {
                cumSum[j][i + 1] = cumSum[j][i] + 1;
            } else {
                cumSum[j][i + 1] = cumSum[j][i];
            }
        }
    }

    std::vector<int> dp(1 << M, 1 << 29);
    dp[0] = 0;
    for (i = 0; i < (1 << M); i++) {
        lastIdx = -1;
        for (j = 0; j < M; j++) {
            if (i & (1 << j)) {
                lastIdx += count[j];
            }
        }

        for (j = 0; j < M; j++) {
            if (!(i & (1 << j))) {
                toAdd = count[j] - (cumSum[j][lastIdx + count[j] + 1] - cumSum[j][lastIdx + 1]);
                dp[i + (1 << j)] = std::min(dp[i + (1 << j)], dp[i] + toAdd);
            }
        }
    }

    std::cout << dp[(1 << M) - 1] << std::endl;

    return 0;
}