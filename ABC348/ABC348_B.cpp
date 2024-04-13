#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, i, j, tmpmax, tmpans;
    cin >> N;
    vector<int> X(N), Y(N);
    vector<vector<int>> dis(N, vector<int>(N));
    for (i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    for (i = 0; i < N; i++) {
        tmpmax = 0;
        tmpans = -1;
        for (j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            dis[i][j] = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
            if (tmpmax < dis[i][j]) {
                tmpmax = dis[i][j];
                tmpans = j;
            }
        }
        cout << tmpans + 1 << endl;
    }

    return 0;
}