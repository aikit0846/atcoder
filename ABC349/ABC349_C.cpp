#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S, T;
    char lastChar;
    bool is_code;
    cin >> S;
    cin >> T;
    lastChar = *(T.end() - 1);

    is_code = false;
    if (lastChar != 'X') {
        auto target = T.begin();
        for (auto iter = S.begin(); iter != S.end(); iter++) {
            if (toupper(*iter) == *target) {
                target++;
                if (target == T.end()) {
                    is_code = true;
                    break;
                }
            }
        }
    } else {
        auto target = T.begin();
        for (auto iter = S.begin(); iter != S.end(); iter++) {
            if (toupper(*iter) == *target) {
                target++;
                if (target == T.end() - 1) {
                    is_code = true;
                    break;
                }
            }
        }
    }

    cout << (is_code ? "Yes" : "No") << endl;

    return 0;
}