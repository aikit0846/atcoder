// AC

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W, N, i, j;
    cin >> H >> W >> N;
    vector<vector<bool>> isWhite(H, vector<bool>(W, true));

    int direction = 0;
    int nowtate = 0;
    int nowyoko = 0;
    for (i = 0; i < N; i++) {
        direction %= 4;

        switch (direction) {
            case 0:
            if (isWhite[nowtate][nowyoko]) {
                isWhite[nowtate][nowyoko] = false;
                nowyoko++;
                // direction++;
            } else {
                isWhite[nowtate][nowyoko] = true;
                nowyoko++;
                // direction--;
            }
            break;
            case 1:
            if (isWhite[nowtate][nowyoko]) {
                isWhite[nowtate][nowyoko] = false;
                nowtate++;
                // direction++;
            } else {
                isWhite[nowtate][nowyoko] = true;
                nowtate++;
                // direction--;
            }
            break;
            case 2:
            if (isWhite[nowtate][nowyoko]) {
                isWhite[nowtate][nowyoko] = false;
                nowyoko--;
                // direction++;
            } else {
                isWhite[nowtate][nowyoko] = true;
                nowyoko--;
                // direction--;
            }
            break;
            case 3:
            if (isWhite[nowtate][nowyoko]) {
                isWhite[nowtate][nowyoko] = false;
                nowtate--;
                // direction++;
            } else {
                isWhite[nowtate][nowyoko] = true;
                nowtate--;
                // direction--;
            }
        }

        if (nowtate >= H) {
            nowtate -= H;
        }
        if (nowyoko >= W) {
            nowyoko -= W;
        }
        if (nowtate < 0) {
            nowtate += H;
        }
        if (nowyoko < 0) {
            nowyoko += W;
        }

        if (isWhite[nowtate][nowyoko]) {
            direction++;
        } else {
            direction--;
        }

        if (direction >= 4) {
            direction -= 4;
        }
        if (direction < 0) {
            direction += 4;
        }


        // for (int k = 0; k < H; k++) {
        //     for (j = 0; j < W; j++) {
        //         if (isWhite[k][j]) {
        //             cout << '.';
        //         } else {
        //             cout << '#';
        //         }
        //     }
        //     cout << endl;
        // }
        // cout << nowtate << " " << nowyoko << " " << direction << endl;
        // cout << endl;
    }

    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            if (isWhite[i][j]) {
                cout << '.';
            } else {
                cout << '#';
            }
        }
        cout << endl;
    }

    return 0;
}