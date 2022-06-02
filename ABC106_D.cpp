#include <iostream>
#include <vector>

int main()
{
    int N, M, Q, i, j, L, R, p, q;
    std::cin >> N >> M >> Q;
    std::vector<std::vector<int>> kukan(N, std::vector<int>(N)), accum(N + 1, std::vector<int>(N + 1));
    for (i = 0; i < M; i++) {
        std::cin >> L >> R;
        kukan[L - 1][R - 1]++;
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            accum[i + 1][j + 1] = accum[i][j + 1] + kukan[i][j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            accum[i + 1][j + 1] += accum[i + 1][j];
        }
    }

    for (i = 0; i < Q; i++) {
        std::cin >> p >> q;
        std::cout << accum[q][q] - accum[p - 1][q] - accum[q][p - 1] + accum[p - 1][p - 1] << std::endl;
    }

    return 0;
}