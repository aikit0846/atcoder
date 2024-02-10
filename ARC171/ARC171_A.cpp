#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, t, N, A, B, T, maxPorn, K;
    bool possible;
    cin >> T;

    for (t = 0; t < T; t++) {
        cin >> N >> A >> B;
        possible = true;

        K = N - A;
        if (possible && K < 0) {
            possible = false;
        }

        if (A == 0) {
            maxPorn = N * ((N + 1) / 2);
        } else if (A >= N / 2) {
            maxPorn = K * K;
        } else {
            maxPorn = K * ((K + A + 1) / 2);
        }

        if (possible && B > maxPorn) {
            possible = false;
        }
        
        cout << (possible ? "Yes" : "No") << endl;
    }

    return 0;
}