#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, i;
    std::cin >> n;
    std::vector<int> a(n);
    for (i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> dp(n, 1e9);
    for (i = 0; i < n; i++) {
        auto it = std::lower_bound(dp.begin(), dp.end(), a[i]);
        *it = a[i];
    }

    std::cout << std::lower_bound(dp.begin(), dp.end(), 1e9) - dp.begin() << std::endl;

    return 0;
}