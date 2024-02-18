// not submitted

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long K, N, L, i, j, initK, initN, ans;
    long long M = 998244353;
    cin >> N >> K >> L;

    initK = 1;
    initN = N - K + 1;

    if (initN > L) {
        cout << 0 << endl;
        return 0;
    } else {
        long long tmp = 1;
        for (i = L; i >= L - initN + 1; i--) {
            tmp *= (i % M);
            tmp %= M;
        }
        ans = (tmp % M);
        ans %= M;
    }

    for (i = 0; i < K - 1; i++) {
        ans *= (L - 1);
        ans %= M;
    }

    cout << ans << endl;

    return 0;
}