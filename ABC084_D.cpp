#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int Q, i, j, maxr;
    std::cin >> Q;
    std::vector<int> l(Q), r(Q);
    maxr = 0;
    for (i = 0; i < Q; i++) {
        std::cin >> l[i] >> r[i];
        maxr = std::max(maxr, r[i]);
    }

    std::vector<bool> furui(maxr + 1, true), is_prime(maxr + 1, true);
    furui[0] = furui[1] = furui[2] = false;
    is_prime[0] = is_prime[1] = false;
    for (i = 2; i * i <= maxr; i++) {
        if (!is_prime[i]) {
            continue;
        }

        for (j = i * 2; j <= maxr; j += i) {
            furui[j] = false;
            is_prime[j] = false;
            if (j * 2 - 1 <= maxr) {
                furui[j * 2 - 1] = false;
            }
        }
    }

    std::vector<int> accum(maxr + 1, 0);
    for (i = 1; i < maxr + 1; i++) {
        if (furui[i]) {
            accum[i] = accum[i - 1] + 1;
        } else {
            accum[i] = accum[i - 1];
        }
    }

    for (i = 0; i < Q; i++) {
        std::cout << accum[r[i]] - accum[l[i] - 1] << std::endl;
    }

    return 0;
}