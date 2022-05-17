#include <iostream>
#include <vector>

int main()
{
    int N, i, j, k, ans, tmp;
    std::cin >> N;
    std::vector<int> x(N), y(N), a(2), v1(2), v2(2);
    std::vector<std::vector<bool>> point(5001, std::vector<bool>(5001, false));
    for (i = 0; i < N; i++) {
        std::cin >> x[i] >> y[i];
        point[x[i]][y[i]] = true;
    }

    ans = 0;
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            a[0] = x[i] - x[j];
            a[1] = y[i] - y[j];
            v1[0] = -a[1];
            v1[1] = a[0];
            v2[0] = a[1];
            v2[1] = -a[0];

            if (x[i] + v1[0] >= 0 && x[i] + v1[0] <= 5000 && y[i] + v1[1] >= 0 && y[i] + v1[1] <= 5000 && x[j] + v1[0] >= 0 && x[j] + v1[0] <= 5000 && y[j] + v1[1] >= 0 && y[j] + v1[1] <= 5000) {
                if (point[x[i] + v1[0]][y[i] + v1[1]] && point[x[j] + v1[0]][y[j] + v1[1]]) {
                    tmp = a[0] * a[0] + a[1] * a[1];
                    if (ans < tmp) {
                        ans = tmp;
                    }
                }
            }
            if (x[i] + v2[0] >= 0 && x[i] + v2[0] <= 5000 && y[i] + v2[1] >= 0 && y[i] + v2[1] <= 5000 && x[j] + v2[0] >= 0 && x[j] + v2[0] <= 5000 && y[j] + v2[1] >= 0 && y[j] + v2[1] <= 5000) {
                if (point[x[i] + v2[0]][y[i] + v2[1]] && point[x[j] + v2[0]][y[j] + v2[1]]) {
                    tmp = a[0] * a[0] + a[1] * a[1];
                    if (ans < tmp) {
                        ans = tmp;
                    }
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}