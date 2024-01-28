// AC

#include <bits/stdc++.h>

using namespace std;


int main()
{
    string S;
    vector<int> num(26, 0);
    cin >> S;

    for (auto iter = S.begin(); iter != S.end(); iter++) {
        num[*iter - 'a']++;
    }

    cout << (char)(max_element(num.begin(), num.end()) - num.begin() + 'a') << endl;

    return 0;
}