#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int H, W, i, j, k, ans;
    std::cin >> H >> W;
    std::vector<std::vector<int>> c(10, std::vector<int>(10)), A(H, std::vector<int>(W));
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            std::cin >> c[i][j];
        }
    }
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<std::vector<int>> minconv(10, std::vector<int>(10, 1e9));
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            minconv[i][j] = c[i][j];
        }
    }
    for (k = 0; k < 10; k++) {
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                minconv[i][j] = std::min(minconv[i][j], minconv[i][k] + minconv[k][j]);
            }
        }
    }

    ans = 0;
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            if (A[i][j] == -1) {
                continue;
            }
            ans += minconv[A[i][j]][1];
        }
    }

    std::cout << ans << std::endl;

    return 0;
}