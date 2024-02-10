// AC

#include <bits/stdc++.h>

using namespace std;

map<long long, long long> memo;

long long rec(long long n)
{
    if (n == 0 || n == 1) {
        return 0;
    }
    
    if (n == 2) {
        return 2;
    }

    if (memo.find(n) != memo.end()) {
        return memo.at(n);
    }

    long long res = n;
    
    if (n % 2 == 0) {
        res = 2 * rec(n / 2) + n;
    } else {
        res = rec((n + 1) / 2) + rec((n - 1) / 2) + n;
    }

    memo.insert(make_pair(n, res));

    return res;
}


int main()
{
    long long i, j, N;
    cin >> N;

    cout << rec(N) << endl;

    return 0;
}