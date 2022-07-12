#include <iostream>
#include <vector>

int main()
{
    long long V, E, i, j, k, s, t, d;
    std::cin >> V >> E;
    std::vector<std::vector<long long>> sp(V, std::vector<long long>(V, 1e17));
    for (i = 0; i < E; i++) {
        std::cin >> s >> t >> d;
        sp[s][t] = d;
    }
    for (i = 0; i < V; i++) {
        sp[i][i] = 0;
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (sp[i][k] < 1e17 && sp[k][j] < 1e17) {
                    sp[i][j] = std::min(sp[i][j], sp[i][k] + sp[k][j]);
                }
            }
        }
    }

    for (i = 0; i < V; i++) {
        if (sp[i][i] < 0) {
            std::cout << "NEGATIVE CYCLE" << std::endl;
            return 0;
        }
    }

    for (i = 0; i < V; i++) {
        for (j = 0; j < V - 1; j++) {
            if (sp[i][j] >= 1e17) {
                std::cout << "INF ";
            } else {
                std::cout << sp[i][j] << " ";
            }
        }
        if (sp[i][V - 1] >= 1e17) {
            std::cout << "INF" << std::endl;
        } else {
            std::cout << sp[i][V - 1] << std::endl;
        }
    }

    return 0;
}