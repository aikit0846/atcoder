#include <iostream>

int main()
{
    int N, i, j, k;
    std::cin >> N;

    for (i = 0; i <= N; i++) {
        for (j = 0; j <= N - i; j++) {
            for (k = 0; k <= N - i - j; k++) {
                std::cout << i << " " << j << " " << k << std::endl;
            }
        }
    }

    return 0;
}