#include <iostream>

int main()
{
    int n, i, prev;
    std::cin >> n;

    std::cout << n << ":";
    for (i = 2; i * i <= n; i++) {
        while (!(n % i)) {
            n /= i;
            std::cout << " " << i;
        }
    }
    if (n > 1) {
        std::cout << " " << n << std::endl;
    } else {
        std::cout << std::endl;
    }

    return 0;
}