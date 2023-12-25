#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    int H, W, A, i, j, k, ans;
    std::cin >> H >> W;
    std::vector<std::vector<int>> c(10, std::vector<int>(10, 1 << 30));
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            std::cin >> c[i][j];
        }
    }

    for (k = 0; k < 10; k++) {
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                c[i][j] = std::min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }

    ans = 0;
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            std::cin >> A;
            if (A >= 0) {
                ans += c[A][1];
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}