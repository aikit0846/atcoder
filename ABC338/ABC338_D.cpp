
// RE
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int N, M, i, j;
    cin >> N >> M;
    vector<int> X(M);
    for (i = 0; i < M; i++) {
        cin >> X[i];
    }

    vector<int> bridgeUseNum(N, 0);
    vector<int> aaa(N, 0);
    int oriLength = 0;
    for (i = 0; i < M - 1; i++) {
        if (X[i + 1] < X[i] && (X[i] - X[i + 1]) > (N / 2)) {
            for (j = X[i]; j < N; j++) {
                bridgeUseNum[j]++;
                oriLength++;
            }
            for (j = 0; j < X[i + 1]; j++) {
                bridgeUseNum[j]++;
                oriLength++;
            }
            aaa[j] = X[i] - X[i + 1];
        } else if (X[i] < X[i + 1] && (X[i + 1] - X[i]) > (N / 2)) {
            for (j = X[i + 1]; j < N; j++) {
                bridgeUseNum[j]++;
                oriLength++;
            }
            for (j = 0; j < X[i]; j++) {
                bridgeUseNum[j]++;
                oriLength++;
            }
            aaa[j] = X[i + 1] - X[i];
        } else if (X[i + 1] > X[i]) {
            for (j = X[i]; j < X[i + 1]; j++) {
                bridgeUseNum[j]++;
                oriLength++;
            }
            aaa[j] = (N - (X[i + 1] - X[i]));
        } else if (X[i] > X[i + 1]) {
            for (j = X[i + 1]; j < X[i]; j++) {
                bridgeUseNum[j]++;
                oriLength++;
            }
            aaa[j] = (N - (X[i] - X[i + 1]));
        }
    }

    int cutIdx = (int)(min_element(bridgeUseNum.begin(), bridgeUseNum.end()) - bridgeUseNum.begin());

    cout << oriLength + bridgeUseNum[cutIdx] * (N - 1) << endl;

    return 0;
}