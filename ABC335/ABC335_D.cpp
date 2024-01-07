#include <iostream>
#include <vector>

int main()
{
    int N, i, j, nowtate, nowyoko, dir;
    std::cin >> N;
    std::vector<std::vector<int>> ans(N, std::vector<int>(N, -1));

    nowtate = 0;
    nowyoko = 0;
    dir = 0;
    ans[nowtate][nowyoko] = 1;
    ans[(N + 1) / 2 - 1][(N + 1) / 2 - 1] = 10000;
    for (i = 2; i <= N * N - 1; i++) {
        if (dir == 0) {
            if (nowyoko + 1 >= N || ans[nowtate][nowyoko + 1] != -1) {
                dir++;
                nowtate++;
                ans[nowtate][nowyoko] = i;
            } else {
                nowyoko++;
                ans[nowtate][nowyoko] = i;
            }
        } else if (dir == 1) {
            if (nowtate + 1 >= N || ans[nowtate + 1][nowyoko] != -1) {
                dir++;
                nowyoko--;
                ans[nowtate][nowyoko] = i;
            } else {
                nowtate++;
                ans[nowtate][nowyoko] = i;
            }
        } else if (dir == 2) {
            if (nowyoko - 1 < 0 || ans[nowtate][nowyoko - 1] != -1) {
                dir++;
                nowtate--;
                ans[nowtate][nowyoko] = i;
            } else {
                nowyoko--;
                ans[nowtate][nowyoko] = i;
            }
        } else {
            if (nowtate - 1 < 0 || ans[nowtate - 1][nowyoko] != -1) {
                dir = 0;
                nowyoko++;
                ans[nowtate][nowyoko] = i;
            } else {
                nowtate--;
                ans[nowtate][nowyoko] = i;
            }
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (ans[i][j] == 10000) {
                std::cout << "T ";
            } else if (j == N - 1) {
                std::cout << ans[i][j] << std::endl;
            } else {
                std::cout << ans[i][j] << " ";
            }
        }
    }

    return 0;
}