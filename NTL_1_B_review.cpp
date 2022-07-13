#include <iostream>

const long long MOD = 1000000007;

long long modpow(long long a, long long n)
{
    long long res = 1;

    while (n > 0) {
        if (n & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        n >>= 1;
    }

    return res;
}

int main()
{
    long long m, n;
    std::cin >> m >> n;

    std::cout << modpow(m, n) << std::endl;

    return 0;
}