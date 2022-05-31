#include <iostream>

const long long MOD = 1000000007;


long long power(long long m, long long n)
{
    if (n == 0) {
        return 1;
    }

    long long tmp = power(m * m % MOD, n / 2);
    if (n % 2) {
        tmp = tmp * m % MOD;
    }

    return tmp;
}


int main()
{
    long long m, n;
    std::cin >> m >> n;

    std::cout << power(m, n) << std::endl;

    return 0;
}