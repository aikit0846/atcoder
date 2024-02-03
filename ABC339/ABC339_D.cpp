// did not submit

#include <bits/stdc++.h>

using namespace std;


int bfs(vector<string> S, int N, int si, int sj, int gi, int gj, int direction)
{
    int nowi, nowj, minRoute;
    queue<vector<int>> que;
    vector<vector<bool>> isVisited(N, vector<bool>(N, false));
    isVisited[si][sj] = true;

    vector<int> start = {si, sj, 0};
    que.push(start);

    nowNum = 0;
    while (!que.empty()) {
        vector<int> now = que.front();
        nowi = now[0];
        nowj = now[1];
        nowNum = now[2];
        isVisited[nowi][nowj] = true;
        que.pop();

        int numNext = 0;
        if (direction == 0) {
            if (nowi - 1 > 0 && S[nowi - 1][nowj] != '#') {
                if (!isVisited[nowi - 1][nowj]) {
                    vector<int> next = {nowi - 1, nowj, nowNum + 1};
                    que.push(next);
                    isVisited[nowi - 1][nowj] = true;
                }
                numNext++;
            }
            if (nowj - 1 > 0 && S[nowi][nowj - 1] != '#') {
                if (!isVisited[nowi][nowj - 1]) {
                    vector<int> next = {nowi, nowj - 1, nowNum + 1};
                    que.push(next);
                    isVisited[nowi][nowj - 1] = true;
                }
                numNext++;
            }
        } else if (direction == 1) {
            if (nowi + 1 < N && S[nowi + 1][nowj] != '#') {
                if (!isVisited[nowi + 1][nowj]) {
                    vector<int> next = {nowi + 1, nowj, nowNum + 1};
                    que.push(next);
                    isVisited[nowi + 1][nowj] = true;
                }
                numNext++;
            }
            if (nowj + 1 < N && S[nowi][nowj + 1] != '#') {
                if (!isVisited[nowi][nowj + 1]) {
                    vector<int> next = {nowi, nowj + 1, nowNum + 1};
                    que.push(next);
                    isVisited[nowi][nowj + 1] = true;
                }
                numNext++;
            }
        } else if (direction == 2) {
            if (nowi - 1 > 0 && S[nowi - 1][nowj] != '#') {
                if (!isVisited[nowi - 1][nowj]) {
                    vector<int> next = {nowi - 1, nowj, nowNum + 1};
                    que.push(next);
                    isVisited[nowi - 1][nowj] = true;
                }
                numNext++;
            }
            if (nowj + 1 < N && S[nowi][nowj + 1] != '#') {
                if (!isVisited[nowi][nowj + 1]) {
                    vector<int> next = {nowi, nowj + 1, nowNum + 1};
                    que.push(next);
                    isVisited[nowi][nowj + 1] = true;
                }
                numNext++;
            }
        } else if (direction == 3) {
            if (nowi + 1 < N && S[nowi + 1][nowj] != '#') {
                if (!isVisited[nowi + 1][nowj]) {
                    vector<int> next = {nowi + 1, nowj, nowNum + 1};
                    que.push(next);
                    isVisited[nowi + 1][nowj] = true;
                }
                numNext++;
            }
            if (nowj - 1 > 0 && S[nowi][nowj - 1] != '#') {
                if (!isVisited[nowi][nowj - 1]) {
                    vector<int> next = {nowi, nowj - 1, nowNum + 1};
                    que.push(next);
                    isVisited[nowi][nowj - 1] = true;
                }
                numNext++;
            }
        }

        if (numNext == 0) {
            return nowNum;
        }
    }

    return nowNum;
}


int main()
{
    int N, i, j, k, pi1 = -1, pj1 = -1, pi2 = -1, pj2 = -1, ans, diffi, diffj;
    vector<string> S(N);
    for (i = 0; i < N; i++) {
        cin >> S[i];
        for (j = 0; j < N; j++) {
            if (S[i][j] == 'P') {
                if (pi1 == -1) {
                    pi1 = i;
                    pj1 = j;
                } else {
                    pi2 = i;
                    pj2 = j;
                }
            }
        }
    }

    // P1とP2の位置関係
    int relation;
    diffi = abs(pi1 - pi2);
    diffj = abs(pj1 - pj2);
    if (pi1 == pi2) {
        relation = 0;
    } else if (pj1 == pj2) {
        relation = 1;
    } else {
        relation = 2;
    }

    if (relation == 0) {
        if (pj1 < pj2) {
            ans = min(pj1 + diffj, N - pj2 - 1 + diffj);
        } else {
            ans = min(pj2 + diffj, N - pj1 - 1 + diffj);
        }
    } else if (relation == 1) {
        ans = min(pi1 + diffi, N - pi2 - 1 + diffi);
        // if (pi1 < pi2) {
        //     ans = min(pi1 + diffi, N - pi2 - 1 + diffi);
        // } else {
        //     ans = min(pi2 + diffi, N - pi1 - 1 + diff1);
        // }
    } else {
        if (pj1 < pj2) {
            ans = min(bfs(S, N, pi1, pj1, 0, 0, 0) + )
        } else {

        }
    }

    return 0;
}