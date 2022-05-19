#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, i, j;
    std::cin >> N;
    std::vector<int> A(N);
    for (i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> dp(N, -1);
    dp[N - 1] = A[0];

    for (i = 1; i < N; i++) {
        auto itr = std::lower_bound(dp.begin(), dp.end(), A[i]);
        *(itr - 1) = A[i];
    }

    std::cout << N - std::count(dp.begin(), dp.end(), -1) << std::endl;

    return 0;
}