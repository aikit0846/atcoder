// AC

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long H, W, N, i, j, tmp;
    cin >> H >> W >> N;

    vector<long long> powNum(26, 0), canPow(26, 0);
    for (i = 0; i < N; i++) {
        cin >> tmp;
        powNum[tmp]++;
    }

    for (i = 0; i < 26; i++) {
        long long sideLen = (1 << i);
        canPow[i] = max((long long)0, (H / sideLen) * (W / sideLen));
    }

    for (i = 25; i >= 0; i--) {
        if (powNum[i] == 0) {
            continue;
        }
        if (canPow[i] < powNum[i]) {
            cout << "No" << endl;
            return 0;
        }

        for (j = i; j >= 0; j--) {
            canPow[j] -= powNum[i] * (1 << (2 * (i - j)));
            canPow[j] = max((long long)0, canPow[j]);
        }
    }

    cout << "Yes" << endl;

    return 0;
}