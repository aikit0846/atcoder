#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

int main()
{
    int i, j, N, num, fn, n1, n2, tmp_all, tmp_odd;
    num = 0;
    do {
        num++;
    } while (num * (num + 1) * (num + 2) / 6 <= 1000000);

    std::vector<int> table(num), dp_all(1000001, 0), dp_odd(1000001, 0);
    for (i = 0; i < num; i++) {
        table[i] = (i + 1) * (i + 2) * (i + 3) / 6;
    }
    
    for (i = 1; i < 1000001; i++) {
        tmp_all = 1 << 29;
        tmp_odd = 1 << 29;
        for (j = 0; j < num; j++) {
            if (i >= table[j]) {
                if (dp_all[i - table[j]] + 1 < tmp_all) {
                    tmp_all = dp_all[i - table[j]] + 1;
                }
                if (table[j] % 2 && dp_odd[i - table[j]] + 1 < tmp_odd) {
                    tmp_odd = dp_odd[i - table[j]] + 1;
                }
            } else {
                break;
            }
        }
        dp_all[i] = tmp_all;
        dp_odd[i] = tmp_odd;
    }
    
    while (true) {
        std::cin >> N;
        if (N == 0) {
            break;
        }

        std::cout << dp_all[N] << " " << dp_odd[N] << std::endl;
    }

    return 0;
}