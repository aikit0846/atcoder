#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long i, N, ans;
    long long M = 998244353;
    cin >> N;
    vector<long long> A(N), unusedNum, unassigned;
    vector<vector<long long>> group(N);
    for (i = 0; i < N; i++) {
        cin >> A[i];
        group[A[i] - 1].emplace_back(i + 1);
    }

    // 各グループの1番小さい数字が使われないで残る
    for (i = 0; i < N; i++) {
        if (group[i].size() != 0) {
            unusedNum.emplace_back(group[i][0]);
            unassigned.emplace_back(group[i][group[i].size() - 1]);
        }
    }

    sort(unusedNum.begin(), unusedNum.end());

    ans = 1;
    long long count = 0;
    for (auto iter = unassigned.begin(); iter != unassigned.end(); iter++) {
        long long lessNum = (long long)(unusedNum.end() - upper_bound(unusedNum.begin(), unusedNum.end(), *iter));
        // cout << lessNum << endl;

        if ((long long)unusedNum.size() - lessNum - count <= 0) {
            ans = 0;
            break;
        }

        ans = (ans * ((long long)unusedNum.size() - lessNum - count)) % M;
        if (ans == 0) {
            break;
        }
        count++;
    }

    cout << ans % M << endl;

    return 0;
}