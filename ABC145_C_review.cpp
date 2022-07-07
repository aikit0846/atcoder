#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stdio.h>

int main()
{
    int N, i, count;
    double sum;
    std::cin >> N;
    std::vector<int> x(N), y(N), order(N);
    for (i = 0; i < N; i++) {
        std::cin >> x[i] >> y[i];
        order[i] = i;
    }

    count = 0;
    sum = 0;
    do {
        count++;
        for (i = 0; i < N - 1; i++) {
            sum += std::sqrt((x[order[i + 1]] - x[order[i]]) * (x[order[i + 1]] - x[order[i]]) + (y[order[i + 1]] - y[order[i]]) * (y[order[i + 1]] - y[order[i]]));
        }
    } while (std::next_permutation(order.begin(), order.end()));

    printf("%.10f\n", sum / count);

    return 0;
}