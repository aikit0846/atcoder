#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    long long N, i, k, ans;
    std::cin >> N;
    std::vector<long long> A(N), accum(N + 1);
    for (i = 0; i < N; i++) {
        std::cin >> A[i];
        accum[i + 1] = accum[i] + A[i];
    }

    for (k = 1; k <= N; k++) {
        ans = 0;
        for (i = 0; i + k <= N; i++) {
            ans = std::max(ans, accum[i + k] - accum[i]);
        }
        std::cout << ans << std::endl;
    }

    return 0;
}