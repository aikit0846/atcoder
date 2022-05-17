#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int main()
{
    int w, h, i, j, nowx, nowy, count;

    while (true) {
        std::cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }
        // std::cout << w << " " << h << std::endl;
        std::vector<std::vector<int>> yoko(h + 2, std::vector<int>(w + 1, 1)), tate(h + 1, std::vector<int>(w + 2, 1));
        for (i = 1; i < h + 1; i++) {
            for (j = 1; j < w; j++) {
                std::cin >> yoko[i][j];
            }
            if (i == h) {
                break;
            }
            for (j = 1; j < w + 1; j++) {
                std::cin >> tate[i][j];
            }
        }

        std::queue<std::tuple<int, int>> q;
        std::vector<std::vector<int>> sp(h + 2, std::vector<int>(w + 2, 1 << 29));

        q.push(std::tuple<int, int>(1, 1));
        sp[1][1] = 1;
        count = 1;
        while (q.size() > 0) {
            std::tuple<int, int> t = q.front();
            q.pop();
            nowx = std::get<0>(t);
            nowy = std::get<1>(t);
            // std::cout << nowx << " " << nowy << std::endl;
            count = sp[nowx][nowy] + 1;

            if (yoko[nowx][nowy - 1] == 0 && count < sp[nowx][nowy - 1]) {
                q.push(std::tuple<int, int>(nowx, nowy - 1));
                sp[nowx][nowy - 1] = count;
            }
            
            if (tate[nowx - 1][nowy] == 0 && count < sp[nowx - 1][nowy]) {
                q.push(std::tuple<int, int>(nowx - 1, nowy));
                sp[nowx - 1][nowy] = count;
            }

            if (yoko[nowx][nowy] == 0 && count < sp[nowx][nowy + 1]) {
                q.push(std::tuple<int, int>(nowx, nowy + 1));
                sp[nowx][nowy + 1] = count;
            }

            if (tate[nowx][nowy] == 0 && count < sp[nowx + 1][nowy]) {
                q.push(std::tuple<int, int>(nowx + 1, nowy));
                sp[nowx + 1][nowy] = count;
            }

            // std::cout << "OK" << std::endl;
        }

        std::cout << ((sp[h][w] == 1 << 29) ? 0 : sp[h][w]) << std::endl;
    }

    return 0;
}