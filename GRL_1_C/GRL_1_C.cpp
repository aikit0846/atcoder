#include <iostream>
#include <vector>
#include <algorithm>


long long add(long long a, long long b) {
    if (a == 1980000001 || (b == 1980000001)) {
        return 1980000001;
    } else {
        return a + b;
    }
}


int main()
{
    long long V, E, i, j, k, s, t, d;
    std::cin >> V >> E;
    std::vector<std::vector<long long>> shortestDist(V, std::vector<long long>(V, 1980000001));
    for (i = 0; i < V; i++) {
        shortestDist[i][i] = 0;
    }
    for (i = 0; i < E; i++) {
        std::cin >> s >> t >> d;
        shortestDist[s][t] = d;
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (shortestDist[i][j] > add(shortestDist[i][k], shortestDist[k][j])) {
                    shortestDist[i][j] = add(shortestDist[i][k], shortestDist[k][j]);
                }
            }
        }
    }

    for (i = 0; i < V; i++) {
        if (shortestDist[i][i] < 0) {
            std::cout << "NEGATIVE CYCLE" << std::endl;
            return 0;
        }
    }

    for (i = 0; i < V; i++) {
        for (j = 0; j < V - 1; j++) {
            if (shortestDist[i][j] >= 1980000001) {
                std::cout << "INF ";
            } else {
                std::cout << shortestDist[i][j] << " ";
            }
        }
        if (shortestDist[i][V - 1] >= 1980000001) {
            std::cout << "INF" << std::endl;
        } else {
            std::cout << shortestDist[i][j] << std::endl;
        }
    }

    return 0;
}