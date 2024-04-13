#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, N, A, C, tmpmax, tmpans;
    cin >> N;

    map<int, int> minInColor;
    for (i = 0; i < N; i++) {
        cin >> A >> C;
        if (minInColor.find(C) == minInColor.end()) {
            minInColor.insert(make_pair(C, A));
        } else {
            if (minInColor[C] > A) {
                minInColor.erase(C);
                minInColor.insert(make_pair(C, A));
            }
        }
    }

    tmpmax = 0;
    for (auto&& [key, value] : minInColor) {
        if (value > tmpmax) {
            tmpmax = value;
        }
    }

    cout << tmpmax << endl;

    return 0;
}