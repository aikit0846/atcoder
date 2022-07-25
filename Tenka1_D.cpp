#include <iostream>
#include <vector>

int main()
{
    int N, i, k, n;
    std::cin >> N;

    k = 0;
    for (i = 3; (i + 1) * (i - 1) / 8 <= N; i += 2) {
        if (N == (i + 1) * (i - 1) / 8) {
            k = i;
            break;
        }
    }

    if (!k) {
        std::cout << "No" << std::endl;
        return 0;
    }
    std::cout << "Yes" << std::endl;
    n = (1 + k) / 2;
    std::cout << n << std::endl;

    std::vector<int> layer(N, 0);
    int nowlayer = 1;
    while (true) {
        int cur = 1, counter = 0;

        std::cout << n - 1;
        for (i = 1; i <= N; i++) {
            if (layer[i - 1] == cur) {
                std::cout << " " << i;
                layer[i - 1] = nowlayer;
                cur++;
                counter++;
            } else if (layer[i - 1] == 0) {
                std::cout << " " << i;
                layer[i - 1] = nowlayer;
                counter++;
            }
            if (counter == n - 1) {
                std::cout << std::endl;
                nowlayer++;
                break;
            }
        }

        if (nowlayer > n) {
            break;
        }
    }

    return 0;
}