#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, i, a, b;
    std::cin >> n;
    std::vector<int> add(1000002), num(1000002);
    for (i = 0; i < n; i++) {
        std::cin >> a >> b;
        add[a]++;
        add[b + 1]--;
    }

    for (i = 0; i < 1000001; i++) {
        num[i + 1] = num[i] + add[i];
    }

    std::cout << *std::max_element(num.begin(), num.end()) << std::endl;

    return 0;
}