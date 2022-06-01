#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    int M, N, K, i, j, a, b, c, d;
    std::cin >> M >> N;
    std::cin >> K;
    std::vector<std::string> chikei(M);
    std::vector<std::vector<int>> Jaccum(M + 1, std::vector<int>(N + 1)), Oaccum(M + 1, std::vector<int>(N + 1)), Iaccum(M + 1, std::vector<int>(N + 1));
    for (i = 0; i < M; i++) {
        std::cin >> chikei[i];
        for (j = 0; j < N; j++) {
            Jaccum[i + 1][j + 1] = Jaccum[i + 1][j] + (chikei[i][j] == 'J');
            Oaccum[i + 1][j + 1] = Oaccum[i + 1][j] + (chikei[i][j] == 'O');
            Iaccum[i + 1][j + 1] = Iaccum[i + 1][j] + (chikei[i][j] == 'I');
        }
    }

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            Jaccum[i + 1][j + 1] += Jaccum[i][j + 1];
            Oaccum[i + 1][j + 1] += Oaccum[i][j + 1];
            Iaccum[i + 1][j + 1] += Iaccum[i][j + 1];
        }
    }

    for (i = 0; i < K; i++) {
        std::cin >> a >> b >> c >> d;
        std::cout << Jaccum[c][d] - Jaccum[a - 1][d] - Jaccum[c][b - 1] + Jaccum[a - 1][b - 1] << " "; 
        std::cout << Oaccum[c][d] - Oaccum[a - 1][d] - Oaccum[c][b - 1] + Oaccum[a - 1][b - 1] << " ";
        std::cout << Iaccum[c][d] - Iaccum[a - 1][d] - Iaccum[c][b - 1] + Iaccum[a - 1][b - 1] << std::endl;
    }

    return 0;
}