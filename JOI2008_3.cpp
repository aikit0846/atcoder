#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    long long N, M, i, j, ans;
    std::cin >> N >> M;
    std::vector<long long> P(N + 1), twoS((N + 1) * (N + 1));
    P[0] = 0;
    for (i = 1; i < N + 1; i++) {
        std::cin >> P[i];
    }
    for (i = 0; i < N + 1; i++) {
        for (j = 0; j < N + 1; j++) {
            twoS[(N + 1) * i + j] = P[i] + P[j];
        }
    }
    std::sort(twoS.begin(), twoS.end(), std::less<long long>{});

    ans = 0;
    for (i = 0; i < (N + 1) * (N + 1); i++) {
        if (twoS[i] > M) {
            break;
        }
        auto itr = std::upper_bound(twoS.begin(), twoS.end(), M - twoS[i]) - 1;
        ans = std::max(twoS[i] + (*itr), ans);
    }

    std::cout << ans << std::endl;

    return 0;
}