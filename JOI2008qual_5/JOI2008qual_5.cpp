#include <iostream>
#include <vector>

int main()
{
    int R, C, i, j, bit, tmp, ans, front;
    std::cin >> R >> C;
    std::vector<std::vector<int>> senbei(R, std::vector<int>(C));
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            std::cin >> senbei[i][j];
        }
    }

    ans = 0;
    for (bit = 0; bit < (1 << R); bit++) {
        tmp = 0;
        for (i = 0; i < C; i++) {
            front = 0;
            for (j = 0; j < R; j++) {
                front = (bit & (1 << j)) ? front + !senbei[j][i] : front + senbei[j][i];
            }
            tmp += std::max(front, R - front);
        }
        ans = std::max(ans, tmp);
    }

    std::cout << ans << std::endl;

    return 0;
}