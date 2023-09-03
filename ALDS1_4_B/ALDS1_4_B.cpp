#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n, q, i, C;
    std::cin >> n;
    std::vector<int> S(n);
    for (i = 0; i < n; i++) {
        std::cin >> S[i];
    }
    std::cin >> q;
    std::vector<int> T(q);
    for (i = 0; i < q; i++) {
        std::cin >> T[i];
    }

    C = 0;
    for (i = 0; i < q; i++) {
        if (T[i] == *std::lower_bound(S.begin(), S.end(), T[i])) {
            C++;
        }
    }

    std::cout << C << std::endl;

    return 0;
}