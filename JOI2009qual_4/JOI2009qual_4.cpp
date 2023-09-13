#include <iostream>
#include <stack>
#include <vector>


int search(std::vector<std::vector<int>> &ice, int nowrow, int nowcol, int m, int n)
{
    int ans = 0;
    
    ice[nowrow][nowcol] = 0;

    if (nowrow < m - 1 && ice[nowrow + 1][nowcol]) {
        std::vector<std::vector<int>> ice_copy = ice;
        ans = std::max(search(ice_copy, nowrow + 1, nowcol, m, n), ans);
    }
    if (nowrow > 0 && ice[nowrow - 1][nowcol]) {
        std::vector<std::vector<int>> ice_copy = ice;
        ans = std::max(search(ice_copy, nowrow - 1, nowcol, m, n), ans);
    }
    if (nowcol < n - 1 && ice[nowrow][nowcol + 1]) {
        std::vector<std::vector<int>> ice_copy = ice;
        ans = std::max(search(ice_copy, nowrow, nowcol + 1, m, n), ans);
    }
    if (nowcol > 0 && ice[nowrow][nowcol - 1]) {
        std::vector<std::vector<int>> ice_copy = ice;
        ans = std::max(search(ice_copy, nowrow, nowcol - 1, m, n), ans);
    }

    return ++ans;
}


int main()
{
    int m, n, i, j, ans;
    std::cin >> m;
    std::cin >> n;
    std::vector<std::vector<int>> ice(m, std::vector<int>(n));
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            std::cin >> ice[i][j];
        }
    }

    ans = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (ice[i][j]) {
                std::vector<std::vector<int>> ice_copy = ice;
                ans = std::max(search(ice_copy, i, j, m, n), ans);
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}