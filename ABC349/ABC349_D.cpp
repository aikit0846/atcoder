#include <bits/stdc++.h>

using namespace std;


long long getPowNum(long long num) {
    long long shift = 0LL;
    long long retShift = shift;
    while (true) {
        if (num >= (1LL << shift) && num % (1LL << shift) == 0LL) {
            retShift = shift;
        }
        if (num < (1LL << shift)) {
            return retShift;
        }
        shift++;
    }
}


long long getPowNumZero(long long num) {
    long long shift = 0LL;
    while (true) {
        if (num < (1LL << shift)) {
            return shift - 1;
        }
        shift++;
    }
}


int main()
{
    long long L, R, pownum, karinum, l, r, ansnum;
    vector<pair<long long, long long>> ans;
    cin >> L >> R;

    ansnum = 0LL;
    l = L;
    do {
        if (l != 0LL) {
            pownum = getPowNum(l);
        } else {
            pownum = getPowNumZero(R);
        }
        karinum = l / (1LL << pownum);
        r = (karinum + 1LL) * (1LL << pownum);

        if (r == R) {
            ansnum++;
            ans.emplace_back(make_pair(l, r));
            break;
        } else if (r > R) {
            do {
                pownum--;
                karinum = l / (1LL << pownum);
                r = (karinum + 1LL) * (1LL << pownum);
            } while (r > R);

            ansnum++;
            ans.emplace_back(make_pair(l, r));
            if (r == R) {
                break;
            }
        } else {
            ansnum++;
            ans.emplace_back(make_pair(l, r));
        }

        l = r;
    } while (true);

    cout << ansnum << endl;
    for (auto iter = ans.begin(); iter != ans.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }

    return 0;
}