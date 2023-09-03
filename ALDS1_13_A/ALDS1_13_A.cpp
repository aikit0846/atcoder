#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int k, i, j, idx;
    bool is_violate;
    std::cin >> k;
    std::vector<int> constraint(8, -1), queen(8);
    for (i = 0; i < k; i++) {
        std::cin >> idx >> constraint[idx];
    }
    for (i = 0; i < 8; i++) {
        queen[i] = i;
    }

    do {
        is_violate = false;
        for (i = 0; i < 8; i++) {
            if (constraint[i] != -1 && constraint[i] != queen[i]) {
                is_violate = true;
                break;
            }

            for (j = 0; j < 8; j++) {
                if (i == j) {
                    continue;
                }
                if (queen[j] - queen[i] == j - i || queen[j] - queen[i] == i - j) {
                    is_violate = true;
                    break;
                }
            }

            if (is_violate) {
                break;
            }
        }

        if (!is_violate) {
            for (i = 0; i < 8; i++) {
                for (j = 0; j < 8; j++) {
                    if (j == queen[i]) {
                        std::cout << "Q";
                    } else {
                        std::cout << ".";
                    }
                    if (j == 7) {
                        std::cout << std::endl;
                    }
                }
            }
            break;
        }
    } while (std::next_permutation(queen.begin(), queen.end()));

    return 0;
}