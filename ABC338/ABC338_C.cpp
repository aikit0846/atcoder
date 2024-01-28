// AC

#include <bits/stdc++.h>

using namespace std;


int main()
{
    int N, i, j, a, ans;
    cin >> N;
    vector<int> Q(N), A(N), B(N);
    for (i = 0; i < N; i++) {
        cin >> Q[i];
    }
    for (i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (i = 0; i < N; i++) {
        cin >> B[i];
    }

    int aMax = 1 << 29;
    for (i = 0; i < N; i++) {
        if (A[i] == 0) {
            continue;
        }
        aMax = min(aMax, Q[i] / A[i]);
    }

    ans = 0;
    for (a = 0; a <= aMax; a++) {
        int bMax = 1 << 29;
        for (i = 0; i < N; i++) {
            if (B[i] == 0) {
                continue;
            }
            bMax = min(bMax, (Q[i] - A[i] * a) / B[i]);
        }

        ans = max(ans, a + bMax);
    }

    cout << ans << endl;

    return 0;
}