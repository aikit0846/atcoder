#include <iostream>
#include <vector>

int main()
{
    int m, n, i, j, k, ansx, ansy, count;
    bool outflag;
    std::cin >> m;
    std::vector<int> xs(m), ys(m), px(m), py(m);
    for (i = 0; i < m; i++) {
        std::cin >> xs[i] >> ys[i];
        px[i] = xs[i] - xs[0];
        py[i] = ys[i] - ys[0];
    }
    std::cin >> n;
    std::vector<int> xm(n), ym(n);
    for (i = 0; i < n; i++) {
        std::cin >> xm[i] >> ym[i];
    }

    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                if (xm[j] == xm[i] + px[k] && ym[j] == ym[i] + py[k]) {
                    count++;
                }
            }
        }
        if (count == m) {
            ansx = xm[i] - xs[0];
            ansy = ym[i] - ys[0];
            break;
        }
    }

    std::cout << ansx << " " << ansy << std::endl;

    return 0;
}