// AC

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, i;
    cin >> N;
    vector<long long> A(N);
    for (i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long minusAns = 0;
    long long tmpNum = 0;
    for (i = 0; i < N; i++) {
        tmpNum += A[i];
        minusAns = min(minusAns, tmpNum);
    }

    cout << -minusAns + tmpNum << endl;

    return 0;
}