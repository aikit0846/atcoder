#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int main()
{
    int R, C, sx, sy, gx, gy, i, j, nowx, nowy, count;
    std::cin >> R >> C;
    std::cin >> sx >> sy;
    std::cin >> gx >> gy;
    std::vector<std::vector<char>> pp(R + 2, std::vector<char>(C + 2, '#'));
    for (i = 1; i < R + 1; i++) {
        for (j = 1; j < C + 1; j++) {
            std::cin >> pp[i][j];
        }
    }

    std::queue<std::tuple<int, int>> q;
    std::vector<std::vector<int>> sp(R + 2, std::vector<int>(C + 2, 1 << 29));

    sp[sx][sy] = 0;
    q.push(std::tuple<int, int>(sx, sy));
    count = 0;
    while (q.size() > 0) {
        std::tuple<int, int> t = q.front();
        q.pop();
        nowx = std::get<0>(t);
        nowy = std::get<1>(t);
        count = sp[nowx][nowy] + 1;

        if (pp[nowx - 1][nowy] == '.' && count < sp[nowx - 1][nowy]) {
            sp[nowx - 1][nowy] = count;
            q.push(std::tuple<int, int>(nowx - 1, nowy));
        }
        if (pp[nowx][nowy + 1] == '.' && count < sp[nowx][nowy + 1]) {
            sp[nowx][nowy + 1] = count;
            q.push(std::tuple<int, int>(nowx, nowy + 1));
        }
        if (pp[nowx + 1][nowy] == '.' && count < sp[nowx + 1][nowy]) {
            sp[nowx + 1][nowy] = count;
            q.push(std::tuple<int, int>(nowx + 1, nowy));
        }
        if (pp[nowx][nowy - 1] == '.' && count < sp[nowx][nowy - 1]) {
            sp[nowx][nowy - 1] = count;
            q.push(std::tuple<int, int>(nowx, nowy - 1));
        }
    }

    std::cout << sp[gx][gy] << std::endl;

    return 0;
}