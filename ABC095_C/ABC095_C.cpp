#include <iostream>

int main()
{
    int A, B, C, X, Y, i, j, k, ans;
    std::cin >> A >> B >> C >> X >> Y;

    ans = 1 << 30;
    for (i = 0; i <= std::max(X, Y) * 2; i += 2) {
        j = std::max(X - i / 2, 0);
        k = std::max(Y - i / 2, 0);

        ans = std::min(A * j + B * k + C * i, ans);
    }

    std::cout << ans << std::endl;

    return 0;
}