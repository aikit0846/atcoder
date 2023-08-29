#include <iostream>
#include <vector>

int main()
{
    int n, i, j, diffx, diffy, ans;
    std::cin >> n;
    std::vector<int> x(n), y(n);
    std::vector<std::vector<bool>> column(5001, std::vector<bool>(5001, false));
    for (i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
        column[x[i]][y[i]] = true;
    }

    ans = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            diffx = x[j] - x[i];
            diffy = y[j] - y[i];

            if (x[i] + diffy >= 0 && y[i] - diffx >= 0 && x[j] + diffy >= 0 && y[j] - diffx >= 0) {
                if (x[i] + diffy <= 5000 && y[i] - diffx <= 5000 && x[j] + diffy <= 5000 && y[j] - diffx <= 5000) {
                    if (column[x[i] + diffy][y[i] - diffx] && column[x[j] + diffy][y[j] - diffx]) {
                        ans = std::max(ans, diffx * diffx + diffy * diffy);
                    }
                }
            }
            if (x[i] - diffy >= 0 && y[i] + diffx >= 0 && x[j] - diffy >= 0 && y[j] + diffx >= 0) {
                if (x[i] - diffy <= 5000 && y[i] + diffx <= 5000 && x[j] - diffy <= 5000 && y[j] + diffx <= 5000) {
                    if (column[x[i] - diffy][y[i] + diffx] && column[x[j] - diffy][y[j] + diffx]) {
                        ans = std::max(ans, diffx * diffx + diffy * diffy);
                    }
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}