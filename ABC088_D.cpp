#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int main()
{
    int H, W, i, j, nowx, nowy, count, wnum;
    std::cin >> H >> W;
    std::vector<std::vector<char>> s(H + 2, std::vector<char>(W + 2, '#'));
    wnum = 0;
    for (i = 1; i < H + 1; i++) {
        for (j = 1; j < W + 1; j++) {
            std::cin >> s[i][j];
            if (s[i][j] == '.') {
                wnum++;
            }
        }
    }

    std::queue<std::tuple<int, int>> q;
    std::vector<std::vector<int>> sp(H + 1, std::vector<int>(W + 2, 1 << 29));

    q.push(std::tuple<int, int>(1, 1));
    sp[1][1] = 1;
    count = 1;
    while (q.size() > 0) {
        std::tuple<int, int> t = q.front();
        q.pop();
        nowx = std::get<0>(t);
        nowy = std::get<1>(t);
        count = sp[nowx][nowy] + 1;

        if (s[nowx][nowy - 1] == '.' && count < sp[nowx][nowy - 1]) {
            q.push(std::tuple<int, int>(nowx, nowy - 1));
            sp[nowx][nowy - 1] = count;
        }

        if (s[nowx - 1][nowy] == '.' && count < sp[nowx - 1][nowy]) {
            q.push(std::tuple<int, int>(nowx - 1, nowy));
            sp[nowx - 1][nowy] = count;
        }

        if (s[nowx][nowy + 1] == '.' && count < sp[nowx][nowy + 1]) {
            q.push(std::tuple<int, int>(nowx, nowy + 1));
            sp[nowx][nowy + 1] = count;
        }

        if (s[nowx + 1][nowy] == '.' && count < sp[nowx + 1][nowy]) {
            q.push(std::tuple<int, int>(nowx + 1, nowy));
            sp[nowx + 1][nowy] = count;
        }
    }

    std::cout << ((sp[H][W] == 1 << 29) ? -1 : wnum - sp[H][W]) << std::endl;

    return 0;
}