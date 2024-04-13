#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, N;
    cin >> N;

    for (i = 1; i <= N; i++) {
        if (i % 3 == 0) {
            cout << "x";
        } else {
            cout << "o";
        }
    }
    cout << endl;

    return 0;
}