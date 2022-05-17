#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    double P, center, left, right;
    std::cin >> P;

    left = 0;
    right = P;
    while (right > left + 1e-9) {
        center = (left + right) / 2;
        if (1 - (P / 1.5) * std::pow(2, -center/1.5) * std::log(2) >= 0) {
            right = center;
        } else {
            left = center;
        }
    }

    std::cout << std::setprecision(9) << right + std::pow(2, -right/1.5) * P << std::endl;

    return 0;
}