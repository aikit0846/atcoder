#include <iostream>
#include <vector>

int main()
{
    int n, q, i, j, bit, tmp;
    std::cin >> n;
    std::vector<int> A(n);
    for (i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    std::cin >> q;
    std::vector<int> m(q);
    for (i = 0; i < q; i++) {
        std::cin >> m[i];
        for (bit = 0; bit < (1 << n); bit++) {
            tmp = 0;
            for (j = 0; j < n; j++) {
                tmp = (bit & (1 << j)) ? tmp + A[j] : tmp;
            }

            if (tmp == m[i]) {
                std::cout << "yes" << std::endl;
                break;
            }
        }
        if (bit == (1 << n)) {
            std::cout << "no" << std::endl;
        }
    }

    return 0;
}