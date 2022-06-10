#include <iostream>
#include <cmath>
#include <stdio.h>

const double PI = acos(-1);

int main()
{
    int a, b, x;
    double ans;
    std::cin >> a >> b >> x;

    if (a * a * b / 2.0 < x) {
        ans = (180 / PI) * std::atan((2.0 * (a * a * b - x)) / (a * a * a));
    } else {
        ans = (180 / PI) * std::atan(a * b * b / (2.0 * x));
    }

    printf("%.10f", ans);

    return 0;
}