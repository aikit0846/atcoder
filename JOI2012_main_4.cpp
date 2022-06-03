#include <iostream>
#include <vector>

int main()
{
    int N, M, i, j, A, B, X, ans;
    std::cin >> N >> M;
    std::vector<std::vector<int>> accum(N + 4);
    for (i = 0; i < N + 4; i++) {
        accum[i] = std::vector<int>(i + 1);
    }

    for (i = 0; i < M; i++) {
        std::cin >> A >> B >> X;

        accum[A + 1][B]++;
        accum[A + 1][B + 1]--;
        accum[A + X + 2][B]--;
        accum[A + X + 3][B + 1]++;
        accum[A + X + 2][B + X + 2]++;
        accum[A + X + 3][B + X + 2]--;
    }

    for (i = 0; i < N + 4; i++) {
        for (j = 1; j < i + 1; j++) {
            accum[i][j] += accum[i][j - 1];
        }
    }

    for (i = 1; i < N + 4; i++) {
        for (j = 0; j < i; j++) {
            accum[i][j] += accum[i - 1][j];
        }
    }

    ans = 0;
    for (i = 1; i < N + 4; i++) {
        for (j = 1; j < i + 1; j++) {
            accum[i][j] += accum[i - 1][j - 1];
            ans += (accum[i][j] > 0);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}