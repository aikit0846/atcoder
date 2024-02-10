// not submitted

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, N, M;
    cin >> N >> M;
    vector<int> A(N), B(M), nowNum(N);
    for (i = 0; i < N; i++) {
        cin >> A[i];
        nowNum[i] = A[i];
    }
    for (i = 0; i < M; i++) {
        cin >> B[i];
    }

    for (i = 0; i < M; i++) {
        for (j = 1; j < N; j++) {
            nowNum[(B[i] + j) % N] += max(0, (nowNum[B[i]] + N - 1) / (N + j));
        }
        nowNum[B[i]] = (nowNum[B[i]] + N - 1) / N;

        for (int k  = 0; k < N - 1; k++) {
            cout << nowNum[k] << " ";
        }
        cout << nowNum[N - 1] << endl;
    }

    for (i = 0; i < N - 1; i++) {
        cout << nowNum[i] << " ";
    }
    cout << nowNum[N - 1] << endl;

    return 0;
}