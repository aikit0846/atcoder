#include <iostream>
#include <vector>

int main()
{
    int H, i, j, k, l, cur, cont, ans;
    bool flag;

    while (true) {
        std::cin >> H;
        if (!H) {
            break;
        }

        std::vector<std::vector<int>> stones(H, std::vector<int>(5));
        for (i = 0; i < H; i++) {
            for (j = 0; j < 5; j++) {
                std::cin >> stones[i][j];
            }
        }

        ans = 0;
        do {
            flag = false;
            for (i = 0; i < H; i++) {
                cont = 1;
                cur = 0;
                j = 1;
                while (j < 5) {
                    if (stones[i][cur] == -1) {
                        cur = j;
                        j = cur + 1;
                        cont = 1;
                    }
                    if (stones[i][j] != stones[i][cur] || stones[i][j] == -1) {
                        if (cont >= 3) {
                            ans += stones[i][cur] * cont;
                            for (k = i; k >= 0; k--) {
                                for (l = cur; l < cur + cont; l++) {
                                    if (k == 0) {
                                        stones[k][l] = -1;
                                    } else {
                                        std::swap(stones[k][l], stones[k - 1][l]);
                                    }
                                }
                            }
                            if (!flag) {
                                flag = true;
                            }
                        }
                        cur = j;
                        j = cur + 1;
                        cont = 1;
                    } else {
                        cont++;
                        j++;
                        if (j == 5 && cont >= 3) {
                            ans += stones[i][cur] * cont;
                            for (k = i; k >= 0; k--) {
                                for (l = cur; l < cur + cont; l++) {
                                    if (k == 0) {
                                        stones[k][l] = -1;
                                    } else {
                                        std::swap(stones[k][l], stones[k - 1][l]);
                                    }
                                }
                            }
                            if (!flag) {
                                flag = true;
                            }
                        }
                    }
                }
            }
        } while (flag);

        std::cout << ans << std::endl;
    }

    return 0;
}