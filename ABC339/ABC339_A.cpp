// AC

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;

    int dotIdx;
    for (auto iter = S.end() - 1; iter != S.begin() - 1; iter--) {
        if (*iter == '.') {
            dotIdx = (int)(iter - S.begin());
            break;
        }
    }

    for (auto iter = S.begin() + dotIdx + 1; iter != S.end(); iter++) {
        cout << *iter;
    }
    cout << endl;

    return 0;
}