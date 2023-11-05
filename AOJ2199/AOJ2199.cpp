#include <iostream>
#include <vector>
#include <algorithm>


int squaredDiff(int num1, int num2)
{
    return (num1 - num2) * (num1 - num2);
}


int nextVal(int previous, int val) {
    if (previous + val > 255) {
        return 255;
    } else if (previous + val < 0) {
        return 0;
    } else {
        return previous + val;
    }
}


int main()
{
    int N, M, i, j;

    while (true) {
        std::cin >> N >> M;
        if (!N && !M) {
            break;
        }
        std::vector<std::vector<int>> dp(N, std::vector<int>(256, 1 << 29));
        std::vector<int> book(M), signal(N);
        for (i = 0; i < M; i++) {
            std::cin >> book[i];
        }
        for (i = 0; i < N; i++) {
            std::cin >> signal[i];
        }

        for (auto &&val : book) {
            dp[0][nextVal(128, val)] = squaredDiff(signal[0], nextVal(128, val));
        }

        for (i = 0; i < N - 1; i++) {
            for (j = 0; j < 256; j++) {
                if (dp[i][j] == 1 << 29) {
                    continue;
                }
                for (auto && val : book) {
                    dp[i + 1][nextVal(j, val)] = std::min(dp[i + 1][nextVal(j, val)], dp[i][j] + squaredDiff(signal[i + 1], nextVal(j, val)));
                }
            }
        }

        std::cout << *std::min_element(dp[N - 1].begin(), dp[N - 1].end()) << std::endl;
    }

    return 0;
}