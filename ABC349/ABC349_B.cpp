#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    map<char, int> dict;
    map<int, int> ansdict; 
    cin >> S;
    for (auto iter = S.begin(); iter != S.end(); iter++) {
        if (dict.find(*iter) == dict.end()) {
            dict.insert(make_pair(*iter, 1));
        } else {
            dict[*iter]++;
        }
    }

    bool is_good = true;
    for (auto iter = dict.begin(); iter != dict.end(); iter++) {
        if (ansdict.find(iter->second) == ansdict.end()) {
            ansdict.insert(make_pair(iter->second, 1));
        } else {
            ansdict[iter->second]++;
        }
    }

    for (auto iter = ansdict.begin(); iter != ansdict.end(); iter++) {
        if (iter->second != 0 && iter->second != 2) {
            is_good = false;
            break;
        }
    }

    cout << (is_good ? "Yes" : "No") << endl;

    return 0;
}