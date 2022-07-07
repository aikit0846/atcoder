#include <iostream>
#include <vector>

int main()
{
    int n, q, i, j, k, div, tmp;
    std::cin >> n;
    std::vector<int> A(n), bit(n);
    for (i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    std::cin >> q;
    std::vector<int> m(q);
    std::vector<bool> flag(q, false);
    for (i = 0; i < q; i++) {
        std::cin >> m[i];
    }

    for (i = 0; i < 1 << n; i++) {
        tmp = 0;
        for (j = 0; j < n; j++) {
            div = 1 << j;
            bit[j] = (i / div) % 2;
            tmp += bit[j] * A[j];
        }

        for (j = 0; j < q; j++) {
            if (!flag[j] && tmp == m[j]) {
                flag[j] = true;
            }
        }
    }

    for (i = 0; i < q; i++) {
        std::cout << (flag[i] ? "yes" : "no") << std::endl;
    }

    return 0;
}