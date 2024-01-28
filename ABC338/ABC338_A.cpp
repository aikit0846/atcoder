// AC

#include <bits/stdc++.h>

using namespace std;


int main()
{
    string S;
    cin >> S;

    auto iter = S.begin();
    if ('A' > *iter || *iter > 'Z') {
        cout << "No" << endl;

        return 0;
    }

    for (auto iter = S.begin() + 1; iter != S.end(); iter++) {
        if  ('a' > *iter || *iter > 'z') {
            cout << "No" << endl;

            return 0;
        } 
    }

    cout << "Yes" << endl;

    return 0;
}