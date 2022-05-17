#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    int R, C, i, j, k, div, omotenum, ans, tmp;
    std::cin >> R >> C;
    std::vector<std::vector<int>> omote(R, std::vector<int>(C)), tmpomote(R, std::vector<int>(C));
    std::vector<int> bit(R);
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            std::cin >> omote[i][j];
        }
    }

    ans = 0;
    for (i = 0; i < 1 << R; i++) {
        tmpomote = omote;
        for (j = 0; j < R; j++) {
            div = 1 << j;
            bit[j] = (i / div) % 2;
        }

        for (j = 0; j < R; j++) {
            if (!bit[j]) {
                continue;
            }
            for (k = 0; k < C; k++) {
                tmpomote[j][k] = (tmpomote[j][k] == 1) ? 0 : 1;
            }
        }

        tmp = 0;
        for (j = 0; j < C; j++) {
            omotenum = 0;
            for (k = 0; k < R; k++) {
                if (tmpomote[k][j]) {
                    omotenum++;
                }
            }
            if (omotenum * 2 > R) {
                tmp += omotenum;
            } else {
                tmp += (R - omotenum);
            }
        }
        if (tmp > ans) {
            ans = tmp;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}