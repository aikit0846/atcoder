#include <iostream>

int main()
{
    int N, i, j, ans, tmp;
    std::cin >> N;

    ans = 0;
    for (i = 1; i <= N; i += 2) {
        tmp = 0;
        for (j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                if (j * j == i) {
                    tmp++;
                } else {
                    tmp += 2;
                }
            }
        }
        
        if (tmp == 8) {
            ans++;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}