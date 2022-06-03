#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    long long N, M, P1, P2, i, j, ans;
    std::cin >> N >> M;
    std::vector<long long> add(N), num(N + 1), A(N - 1), B(N - 1), C(N - 1);
    std::cin >> P1;
    for (i = 1; i < M; i++) {
        std::cin >> P2;
        add[std::min(P1, P2) - 1]++;
        add[std::max(P1, P2) - 1]--;
        P1 = P2;
    }
    for (i = 0; i < N - 1; i++) {
        std::cin >> A[i] >> B[i] >> C[i];
    }

    ans = 0;
    for (i = 0; i < N; i++) {
        num[i + 1] = num[i] + add[i];
        ans += std::min(num[i + 1] * A[i], num[i + 1] * B[i] + C[i]);
    }

    std::cout << ans << std::endl;

    return 0;
}