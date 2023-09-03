#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>

int main()
{
    int N, i, count, idx1, idx2;
    std::cin >> N;
    std::vector<int> x(N), y(N), order(N);
    for (i = 0; i < N; i++) {
        std::cin >> x[i] >> y[i];
        order[i] = i;
    }
    double ans, tmp;
    
    ans = 0;
    count = 0;
    do {
        tmp = 0.0;
        for (i = 0; i < N - 1; i++) {
            idx1 = order[i];
            idx2 = order[i + 1];
            tmp += std::sqrt((x[idx2] - x[idx1]) * (x[idx2] - x[idx1]) + (y[idx2] - y[idx1]) * (y[idx2] - y[idx1]));
        }
        ans += tmp;
        count++;
    } while (std::next_permutation(order.begin(), order.end()));

    ans /= count;

    printf("%.10f\n", ans);

    return 0;
}