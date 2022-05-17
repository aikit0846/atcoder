#include <iostream>
#include <vector>

int max_depth = 0;

void check(std::vector<std::vector<int>> table, int sx, int sy, int depth)
{
    table[sx][sy] = 0;

    if (table[sx - 1][sy]) {
        check(table, sx - 1, sy, depth + 1);
    }
    if (table[sx][sy + 1]) {
        check(table, sx, sy + 1, depth + 1);
    }
    if (table[sx + 1][sy]) {
        check(table, sx + 1, sy, depth + 1);
    }
    if (table[sx][sy - 1]) {
        check(table, sx, sy - 1, depth + 1);
    }

    table[sx][sy] = 1;

    if (!table[sx - 1][sy] && !table[sx][sy + 1] && !table[sx + 1][sy] && !table[sx][sy - 1]) {
        if (depth > max_depth) {
            max_depth = depth;
        }
        return;
    }
}

int main()
{
    int m, n, i, j;
    std::cin >> m;
    std::cin >> n;
    std::vector<std::vector<int>> ice(n + 2, std::vector<int>(m + 2, 0));
    for (i = 1; i < n + 1; i++) {
        for (j = 1; j < m + 1; j++) {
            std::cin >> ice[i][j];
        }
    }

    for (i = 1; i < n + 1; i++) {
        for (j = 1; j < m + 1; j++) {
            if (ice[i][j]) {
                check(ice, i, j, 1);
            }
        }
    }

    std::cout << max_depth << std::endl;

    return 0;
}