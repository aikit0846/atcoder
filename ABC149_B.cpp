#include <iostream>

int main()
{
    long long A, B, K;
    std::cin >> A >> B >> K;

    if (K >= A + B) {
        std::cout << 0 << " " << 0 << std::endl;
    } else {
        if (K >= A) {
            std::cout << 0 << " " << B - (K - A) << std::endl;
        } else {
            std::cout << A - K << " " << B << std::endl;
        }
    }

    return 0;
}