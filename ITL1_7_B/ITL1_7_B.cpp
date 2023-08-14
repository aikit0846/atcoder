#include <iostream>

int main()
{
    int n, x, i, j, k, ans;

    while (true) {
        std::cin >> n >> x;
        if (n ==  0 && x == 0) {
            break;
        }

        ans = 0;
        for (i = 1; i <= n; i++) {
            for (j = i + 1; j <= n; j++) {
                for (k = j + 1; k <= n; k++) {
                    if (i + j + k == x) {
                        ans++;
                        break;
                    }
                }
            }
        }
        
        std::cout << ans << std::endl;
    }

    return 0;
}