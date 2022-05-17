#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int k, i, j;
    std::cin >> k;
    std::vector<int> Qr(k), Qc(k), P(8), r(8), c(8);
    bool flag;
    for (i = 0; i < k; i++) {
        std::cin >> Qr[i] >> Qc[i];
    }
    for (i = 0; i < 8; i++) {
        P[i] = i;
    }

    do {
        flag = true;
        for (i = 0; i < k; i++) {
            if (Qc[i] != P[Qr[i]]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            continue;
        }
        for (i = 0; i < 8; i++) {
            r[i] = i;
            c[i] = P[i];
            for (j = 0; j < i; j++) {
                if (std::abs(r[i] - r[j]) == std::abs(c[i] - c[j])) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            for (i = 0; i < 8; i++) {
                for (j = 0; j <= c[i] - 1; j++) {
                    std::cout << ".";
                }
                std::cout << "Q";
                for (j = c[i] + 1; j < 8; j++) {
                    std::cout << ".";
                }
                std::cout << std::endl;
            }
            break;
        }
    } while (std::next_permutation(P.begin(), P.end()));

    return 0;
}