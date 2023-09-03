#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    long N, i, upper, center, lower, ans;
    bool is_feasible;
    std::cin >> N;
    std::vector<long> H(N), S(N);
    std::vector<double> limit(N);
    upper = 0;
    for (i = 0; i < N; i++) {
        std::cin >> H[i] >> S[i];
        upper = std::max(upper, H[i] + N * S[i]);
    }

    lower = 0;
    while (true) {
        if (upper - lower <= 1) {
            ans = upper;
            break;
        }
        center = (lower + upper) / 2;
        is_feasible = true;

        for (i = 0; i < N; i++) {
            limit[i] = static_cast<double>(center - H[i]) / static_cast<double>(S[i]);
        }
        std::sort(limit.begin(), limit.end());
        for (i = 0; i < N; i++) {
            if (limit[i] < static_cast<double>(i)) {
                is_feasible = false;
                break;
            }
        }

        if (is_feasible) {
            upper = center;
        } else {
            lower = center;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}