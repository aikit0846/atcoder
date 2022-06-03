#include <iostream>
#include <vector>

int main()
{
    int n, i, idx, prev, left, col, ans;
    std::cin >> n;
    std::vector<int> array(n);

    std::cin >> col;
    idx = 0;
    array[idx] = 1;
    left = prev = col;

    for (i = 1; i < n; i++) {
        std::cin >> col;
        if (col == prev) {
            array[idx]++;
        } else if (!((i + 1) % 2)) {
            if (idx == 0) {
                array[idx]++;
                left = col;
            } else {
                array[idx - 1] += array[idx] + 1;
                array[idx] = 0;
                idx--;
            }
        } else {
            idx++;
            array[idx] = 1;
        }
        prev = col;
    }

    ans = 0;
    if (left) {
        for (i = 1; i < n; i += 2) {
            ans += array[i];
        }
    } else {
        for (i = 0; i < n; i += 2) {
            ans += array[i];
        }
    }

    std::cout << ans << std::endl;

    return 0;
}