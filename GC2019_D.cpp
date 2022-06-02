#include <iostream>
#include <vector>

int main()
{
    long long H, W, K, V, A, price, area, i, j, k, l, ans;
    std::cin >> H >> W >> K >> V;
    std::vector<std::vector<long long>> accum(H + 1, std::vector<long long>(W + 1));
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            std::cin >> A;
            accum[i + 1][j + 1] = accum[i + 1][j] + A + K;
        }
    }
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            accum[i + 1][j + 1] += accum[i][j + 1];
        }
    }

    ans = 0;
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            for (k = i; k < H; k++) {
                for (l = j; l < W; l++) {
                    price = accum[k + 1][l + 1] - accum[k + 1][j] - accum[i][l + 1] + accum[i][j];
                    area = (k - i + 1) * (l - j + 1);
                    if (price > V) {
                        break;
                    }
                    if (area > ans) {
                        ans = area;
                    }
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}