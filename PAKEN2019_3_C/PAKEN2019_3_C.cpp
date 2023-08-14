#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    long N, M, i, j, k, ans, score;
    std::cin >> N >> M;
    std::vector<std::vector<long>> A(N, std::vector<long>(M));
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    ans = 0;
    for (i = 0; i < M; i++) {
        for (j = i + 1; j < M; j++) {
            score = 0;
            for (k = 0; k < N; k++) {
                score += std::max(A[k][i], A[k][j]);
            }

            ans = std::max(ans, score);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}