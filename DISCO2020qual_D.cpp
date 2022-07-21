#include <iostream>

int main()
{
    long long M, i, ans, d, c, quot, rema;
    std::cin >> M;

    ans = 0;
    quot = 0;
    rema = 0;
    for (i = 0; i < M; i++) {
        std::cin >> d >> c;
        ans += c;
        quot += d * c / 9;
        rema += d * c % 9;
    }
    quot += rema / 9;
    if (rema % 9 == 0) {
        quot--;
    }
    ans += (quot - 1);


    std::cout << ans << std::endl;

    return 0;
}