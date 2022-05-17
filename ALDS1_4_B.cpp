#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n, q, i, j, ans;
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

    ans = 0;
    for (i = 0; i < q; i++) {
        if (T[i] == *std::lower_bound(S.begin(), S.end(), T[i])) {
            ans++;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}