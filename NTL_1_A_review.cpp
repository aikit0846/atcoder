#include <iostream>

int main()
{
    int n, i, original;
    std::cin >> n;
    original = n;

    std::cout << n << ":";
    while (n % 2 == 0) {
        n /= 2;
        std::cout << " " << 2;
    }
    for (i = 3; i * i <= original; i += 2) {
        while (n % i == 0) {
            n /= i;
            std::cout << " " << i;
        }
    }
    if (n > 1) {
        std::cout << " " << n;
    }
    std::cout << std::endl;

    return 0;
}