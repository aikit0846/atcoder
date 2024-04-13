#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, N, tmpsum, tmp;
    cin >> N;
    tmpsum = 0;
    for (i = 0; i < N - 1; i++) {
        cin >> tmp;
        tmpsum += tmp;
    }

    cout << -tmpsum << endl;

    return 0;
}