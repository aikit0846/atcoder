#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    int N, K, i, j, k;
    std::cin >> N >> K;
    std::vector<int> A(K), B(K);
    for (i = 0; i < K; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::vector<std::vector<int>> dp_num(N + 1, std::vector<int>(6, 0));
    std::vector<std::vector<bool>> dp_bool(N + 1, std::vector<bool>(6, true));

    for (i = 0; i < K; i++) {
        for (j = 0; j < 6; j++) {
            if (j != 2 * (B[i] - 1) && j != 2 * (B[i] - 1) + 1) {
                dp_bool[A[i] - 1][j] = false;
            }
        }
    }
    for (j = 0; j < 6; j++) {
        if (!(j % 2) && dp_bool[0][j]) {
            dp_num[0][j] = 1;
        }
    }

    for (i = 1; i < N; i++) {
        for (j = 0; j < 6; j++) {
            if (j % 2 && dp_bool[i][j]) {
                dp_num[i][j] = dp_num[i - 1][j - 1];
            } else if (!(j % 2) && dp_bool[i][j]) {
                for (k = 0; k < 6; k++) {
                    if (k == j || k == j + 1) {
                        continue;
                    }
                    dp_num[i][j] += dp_num[i - 1][k];
                    dp_num[i][j] %= 10000;
                }
            }
        }
    }

    std::cout << std::accumulate(dp_num[N - 1].begin(), dp_num[N - 1].end(), 0) % 10000 << std::endl;

    return 0;
}