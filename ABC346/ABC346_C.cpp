#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, K, i, j, ans, tmp;
    cin >> N >> K;
    set<long long> s;
    for (i = 0; i < N; i++) {
        cin >> tmp;
        if (tmp >= 1 && tmp <= K) {
            s.insert(tmp);
        }
    }
    
    ans = K * (K + 1) / 2;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        ans -= *iter;
    }

    cout << ans << endl;

    return 0;
}