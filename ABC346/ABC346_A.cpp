#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, N;
    cin >> N;
    vector<int> A(N);
    for (i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (i = 0; i < N - 2; i++) {
        cout << A[i] * A[i + 1] << " ";
    }
    cout << A[N - 2] * A[N - 1] << endl;

    return 0;
}