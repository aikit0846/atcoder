#include <iostream>
#include <vector>
#include <algorithm>

const long long MOD = 1000000007;

int main()
{
    long long N, i, ai, ans;
    std::cin >> N;
    std::vector<long long> counter(N);

    ans = 1;
    for (i = 0; i < N; i++) {
        std::cin >> ai;
        if (ai != 0) {
            ans = ans * std::max(counter[ai - 1] - counter[ai], 0LL) % MOD;
        } else {
            ans = ans * (3 - counter[ai]) % MOD;
        }
        counter[ai]++;
        if (!ans) {
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}