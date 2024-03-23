#include <bits/stdc++.h>

using namespace std;

int main()
{
    int W, B;
    vector<vector<int>> ok_list_over_seven = {
        {1, 0}, {1, 1}, {2, 0}, {2, 1}, {3, 1}, {3, 2},
        {4, 2}, {4, 3}, {5, 2}, {5, 3}, {5, 4}, {6, 3}, {6, 4},
        {6, 5}, {7, 4}, {7, 5}, {7, 6}, {8, 5}, {8, 6}, {8, 7},
        {9, 6}, {9, 7}, {9, 8}, {10, 7}, {10, 8}, {11, 7}, {11, 8},
        {11, 9}, {12, 8}, {12, 9}, {12, 10}
    };
    vector<vector<int>> ok_list_under_seven = {
        {0, 1}, {1, 0}, {1, 1}, {2, 0}, {2, 1}, {3, 1}, {3, 2},
        {4, 2}, {4, 3}, {5, 3}, {5, 4}, {6, 4},
        {6, 5}, {7, 5}
    };
    cin >> W >> B;

    bool is_ok = false;

    if (W <= 7) {
        for (auto iter = ok_list_under_seven.begin(); iter != ok_list_under_seven.end(); iter++) {
            if (W == (*iter)[0] && B == (*iter)[1]) {
                is_ok = true;
            }
        }
    } else {
        while (W >= 0 && B >= 0) {
            for (auto iter = ok_list_over_seven.begin(); iter != ok_list_over_seven.end(); iter++) {
                if (W == (*iter)[0] && B == (*iter)[1]) {
                    is_ok = true;
                }
            }

            W -= 7;
            B -= 5;
        }
    }

    if (is_ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}