#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

int main()
{
    int H, W, K, i, j, k, l, m, n, count, cur1, cur2, cnum, tmp, tmpans, ans;
    bool flag;
    std::cin >> H >> W >> K;
    std::vector<std::vector<int>> c(H, std::vector<int>(W)), original(H, std::vector<int>(W));
    std::string s_in;
    for (i = 0; i < H; i++) {
        std::cin >> s_in;
        for (j = 0; j < W; j++) {
            original[i][j] = s_in[j] - '0';
        }
    }

    if (K == 1) {
        int minc = 1e9, sumc = 0;
        for (i = 0; i < H; i++) {
            minc = std::min(minc, *std::min_element(original[i].begin(), original[i].end()));
            sumc += std::accumulate(original[i].begin(), original[i].end(), 0);
        }

        std::cout << sumc - minc << std::endl;
        return 1;
    }
    if (K >= 4) {
        std::cout << 0 << std::endl;
        return 1;
    }

    ans = 0;
    for (i = 1; i < H; i++) {
        for (j = 0; j < W; j++) {
            c = original;
            // std::cout << "a" << std::endl;
            // (i, j)を削除して落ちてくる
            for (k = i; k >= 1; k--) {
                std::swap(c[k][j], c[k - 1][j]);
            }
            c[0][j] = -1;

            // 消滅の連鎖
            count = 0;
            tmpans = 0;
            while (true) {
                tmp = 0;
                // std::cout << "b" << std::endl;
                for (k = 0; k < H; k++) {
                    cur1 = 0;
                    cur2 = cur1 + 1;
                    cnum = c[k][cur1];
                    while (cur2 < W) {
                        if (cnum == -1) {
                            cur1++;
                            cur2 = cur1 + 1;
                            cnum = c[k][cur1];
                            continue;
                        }
                        if (c[k][cur2] != cnum) {
                            if (cur2 - cur1 >= K) {
                                // std::cout << i << " " << j << " " << cnum << std::endl;
                                tmp += (cnum * (cur2 - cur1));
                                for (l = cur1; l < cur2; l++) {
                                    c[k][l] = -1;
                                }
                            }
                            cur1 = cur2;
                            cur2 = cur1 + 1;
                            cnum = c[k][cur1];
                        } else {
                            cur2++;
                            if (cur2 >= W && cur2 - cur1 >= K) {
                                // std::cout << i << " " << j << " " << cnum << std::endl;
                                tmp += (cnum * (cur2 - cur1));
                                for (l = cur1; l < cur2; l++) {
                                    c[k][l] = -1;
                                }
                            }
                        }
                    }
                }
                // std::cout << "c" << std::endl;

                if (!tmp) {
                    break;
                }

                std::vector<std::vector<int>> newc(H, std::vector<int>(W, -1));
                std::vector<int> now(W, H - 1);
                for (k = H - 1; k >= 0; k--) {
                    for (l = 0; l < W; l++) {
                        if (c[k][l] != -1) {
                            newc[now[l]][l] = c[k][l];
                            now[l]--;
                        }
                    }
                }
                c = newc;

                // std::cout << count << " " << tmp << std::endl;
                tmpans += ((1 << count) * tmp);
                count++;
            }
            ans = std::max(ans, tmpans);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}