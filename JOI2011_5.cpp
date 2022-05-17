#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <tuple>

int main()
{
    int H, W, N, i, j, nowx, nowy, count, idx, ans;
    std::cin >> H >> W >> N;
    std::vector<std::vector<char>> JOI(H + 2, std::vector<char>(W + 2, 'X'));
    std::map<char, std::tuple<int, int>> loc;
    for (i = 1; i < H + 1; i++) {
        for (j = 1; j < W + 1; j++) {
            std::cin >> JOI[i][j];
            if (JOI[i][j] != 'X') {
                loc.insert({JOI[i][j], std::tuple<int, int>(i, j)});
            }
        }
    }
    std::vector<char> farm = {'S'};
    for (i = 0; i < N; i++) {
        farm.emplace_back('1' + i);
    }
    // std::cout << farm[1] << std::endl;

    ans = 0;
    for (idx = 0; idx < N; idx++) {
        char s = farm[idx];
        std::queue<std::tuple<int, int>> q;
        std::vector<std::vector<int>> sp(H + 2, std::vector<int>(W + 2, 1 << 29));

        q.push(loc[s]);
        sp[std::get<0>(loc[s])][std::get<1>(loc[s])] = 0;
        count = 0;
        while (q.size() > 0) {
            std::tuple<int, int> t = q.front();
            q.pop();
            nowx = std::get<0>(t);
            nowy = std::get<1>(t);
            count = sp[nowx][nowy] + 1;

            // std::cout << nowx << " " << nowy << std::endl;

            if (JOI[nowx - 1][nowy] != 'X' && count < sp[nowx - 1][nowy]) {
                q.push(std::tuple<int, int>(nowx - 1, nowy));
                sp[nowx - 1][nowy] = count;
            }
            if (JOI[nowx][nowy + 1] != 'X' && count < sp[nowx][nowy + 1]) {
                q.push(std::tuple<int, int>(nowx, nowy + 1));
                sp[nowx][nowy + 1] = count;
            }
            if (JOI[nowx + 1][nowy] != 'X' && count < sp[nowx + 1][nowy]) {
                q.push(std::tuple<int, int>(nowx + 1, nowy));
                sp[nowx + 1][nowy] = count;
            }
            if (JOI[nowx][nowy - 1] != 'X' && count < sp[nowx][nowy - 1]) {
                q.push(std::tuple<int, int>(nowx, nowy - 1));
                sp[nowx][nowy - 1] = count;
            }
        }

        // std::cout << "a" << std::endl;
        ans += sp[std::get<0>(loc[farm[idx + 1]])][std::get<1>(loc[farm[idx + 1]])];
    }

    std::cout << ans << std::endl;

    return 0;
}