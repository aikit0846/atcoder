#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>

struct Circle {
    int x;
    int y;
    int r;
};


int main()
{
    int N, M, i, j;
    double ans;
    std::cin >> N >> M;
    std::vector<Circle> C(N + M);

    ans = static_cast<double>(1e9);
    for (i = 0; i < N; i++) {
        std::cin >> C[i].x >> C[i].y >> C[i].r;
        ans = std::min(ans, static_cast<double>(C[i].r));
    }
    for (i = N; i < N + M; i++) {
        std::cin >> C[i].x >> C[i].y;
    }

    for (i = N; i < N + M; i++) {
        for (j = 0; j < N; j++) {
            ans = std::min(ans, std::sqrt((C[i].x - C[j].x) * (C[i].x - C[j].x) + (C[i].y - C[j].y) * (C[i].y - C[j].y)) - C[j].r);
        }
        for (j = N; j < N + M; j++) {
            if (i == j) {
                continue;
            }
            ans = std::min(ans, std::sqrt((C[i].x - C[j].x) * (C[i].x - C[j].x) + (C[i].y - C[j].y) * (C[i].y - C[j].y)) / 2);
        }
    }

    printf("%.15f", ans);

    return 0;
}