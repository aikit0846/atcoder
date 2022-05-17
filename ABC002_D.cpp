#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    int N, M, i, j, k, div, tmp, ans;
    bool is_ng;
    std::cin >> N >> M;
    std::vector<int> x(M), y(M), bit(N);
    std::vector<std::vector<bool>> know(N, std::vector<bool>(N, false));
    for (i = 0; i < M; i++) {
        std::cin >> x[i] >> y[i];
        know[x[i] - 1][y[i] - 1] = true;
        know[y[i] - 1][x[i] - 1] = true;
    }

    ans = 0;
    for (i = 0; i < 1 << N; i++) {
        is_ng = false;
        for (j = 0; j < N; j++) {
            div = 1 << j;
            bit[j] = (i / div) % 2;
        }
        for (j = 0; j < N - 1; j++) {
            if (is_ng) {
                break;
            }
            if (!bit[j]) {
                continue;
            }
            for (k = j + 1; k < N; k++) {
                if (!bit[k]) {
                    continue;
                }
                if (!know[j][k]) {
                    is_ng = true;
                    break;
                }
            }
        }
        if (!is_ng) {
            tmp = std::accumulate(bit.begin(), bit.end(), 0);
            if (tmp > ans) {
                ans = tmp;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}