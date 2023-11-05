#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


int main()
{
    int i, j, k, n, input;
    int MAX_NUM = (int)std::pow(10, 6);
    std::vector<int> dp_all(MAX_NUM, 1 << 29), dp_odd(MAX_NUM, 1 << 29);

    for (n = 1; n * (n + 1) * (n + 2) / 6 <= MAX_NUM; n++) {
        k = n * (n + 1) * (n + 2) / 6;
        dp_all[k - 1] = 1;
        dp_odd[k - 1] = ((k % 2) ? 1 : dp_odd[k - 1]);
    }

    for (i = 0; i < MAX_NUM; i++) {
        for (j = 1; j * (j + 1) * (j + 2) / 6 <= MAX_NUM - i - 1; j++) {
            k = j * (j + 1) * (j + 2) / 6;
            dp_all[i + k] = std::min(dp_all[i + k], dp_all[i] + 1);
            dp_odd[i + k] = ((k % 2) ? std::min(dp_odd[i + k], dp_odd[i] + 1) : dp_odd[i + k]);
        }
    }

    while (true) {
        std::cin >> input;
        if (!input) {
            break;
        }

        std::cout << dp_all[input - 1] << " " << dp_odd[input - 1] << std::endl;
    }

    return 0;
}