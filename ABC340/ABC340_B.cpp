// AC

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, Q, kind, val;
    vector<int> col;
    cin >> Q;
    for (i = 0; i < Q; i++) {
        cin >> kind >> val;

        if (kind == 1) {
            col.emplace_back(val);
        } else if (kind == 2) {
            cout << col[col.size() - val] << endl;
        }
    }

    return 0;
}