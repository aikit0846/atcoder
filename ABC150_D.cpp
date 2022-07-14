#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    long long N, M, i, b;
    std::cin >> N >> M;
    std::vector<long long> a(N);
    for (i = 0; i < N; i++) {
        std::cin >> b;
        a[i] = b / 2;
    }

    long long l = std::accumulate(a.begin(), a.end(), 1, [](long long m, long long n) {
        return std::lcm(m, n);
    });

    for (i = 0; i < N; i++) {
        if ((l / a[i]) % 2 == 0 || l > M) {
            std::cout << 0 << std::endl;
            return 0;
        }
    }

    std::cout << (M - l) / (2 * l) + 1 << std::endl;

    return 0;
}