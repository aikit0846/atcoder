// did not submit

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, D, i, j, tmp, ans;
    cin >> N >> D;
    vector<int> A(N), B(N - 1, 1 << 29), C(N, 0);
    for (i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (i = 0; i < N - 1; i++) {
        B[i] = abs(A[i + 1] - A[i]);
    }

    ans = 1;
    tmp = 0;
    for (i = 0; i < N - 1; i++) {
        if (B[i] <= D) {
            ans++;
        }
    }

    C[0] = B[0];
    for (i = 0; i < N - 1; i++) {
        if (B[i] <= D) {
            ans++;
            C[i + 1] = 0;
        } else {
            C[i + 1] = C[i] + B[i];
        }
    }

    cout << ans << endl;

    return 0;
}