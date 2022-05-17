#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

const int F_NUM = 24;  // テストケースの数
const int TIME_LIMIT = 2;  // 時間制限

int main()
{
    int fnum, myans, ans;
    int N, i, j, k;
    double start;
    std::string in_path, out_path;

    for (fnum = 1; fnum <= F_NUM; fnum++) {
        // 標準入力をテストケースの入力ファイルに設定
        if (fnum <= 4) {
            in_path = "in/00-sample-0" + std::to_string(fnum) + ".txt";
        } else if (fnum <= 9) {
            in_path = "in/01-corner-1-0" + std::to_string(fnum - 4) + ".txt";
        } else if (fnum <= 13) {
            in_path = "in/02-random-alpha-2-0" + std::to_string(fnum - 9) + ".txt";
        } else if (fnum <= 17) {
            in_path = "in/03-corner-2-0" + std::to_string(fnum - 13) + ".txt";
        } else if (fnum <= 21) {
            in_path = "in/04-random-alpha-3-0" + std::to_string(fnum - 17) + ".txt";
        } else if (fnum <= 23) {
            in_path = "in/05-random-beta-3-0" + std::to_string(fnum - 21) + ".txt";
        } else {
            in_path = "in/06-straight-4-01.txt";
        }
        std::ifstream in(in_path);
        std::cin.rdbuf(in.rdbuf());
        start = clock();

        // 標準入力
        std::cin >> N;
        std::vector<std::vector<char>> S(N, std::vector<char>(5));
        for (i = 0; i < 5; i++) {
            for (j = 0; j < N; j++) {
                std::cin >> S[j][i];
            }
        }

        // アルゴリズムの内容
        int inf = 1 << 29;
        std::vector<std::vector<int>> dp(N, std::vector<int>(3, inf));
        std::vector<char> color = {'R', 'B', 'W'};
        for (j = 0; j < 3; j++) {
            dp[0][j] = 5 - std::count(S[0].begin(), S[0].end(), color[j]);
        }
        for (i = 1; i < N; i++) {
            dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]) + (5 - std::count(S[i].begin(), S[i].end(), color[0]));
            dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][2]) + (5 - std::count(S[i].begin(), S[i].end(), color[1])); 
            dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][1]) + (5 - std::count(S[i].begin(), S[i].end(), color[2]));  
        }
        myans = *std::min_element(dp[N - 1].begin(), dp[N - 1].end());

        // 時間測定完了
        double time = (clock() - start) / CLOCKS_PER_SEC;

        // 標準入力をテストケースの出力ファイルに設定
        if (fnum <= 4) {
            out_path = "out/00-sample-0" + std::to_string(fnum) + ".txt";
        } else if (fnum <= 9) {
            out_path = "out/01-corner-1-0" + std::to_string(fnum - 4) + ".txt";
        } else if (fnum <= 13) {
            out_path = "out/02-random-alpha-2-0" + std::to_string(fnum - 9) + ".txt";
        } else if (fnum <= 17) {
            out_path = "out/03-corner-2-0" + std::to_string(fnum - 13) + ".txt";
        } else if (fnum <= 21) {
            out_path = "out/04-random-alpha-3-0" + std::to_string(fnum - 17) + ".txt";
        } else if (fnum <= 23) {
            out_path = "out/05-random-beta-3-0" + std::to_string(fnum - 21) + ".txt";
        } else {
            out_path = "out/06-straight-4-01.txt";
        }
        std::ifstream out(out_path);
        std::cin.rdbuf(out.rdbuf());
        
        // 標準入力（答えの入力）
        std::cin >> ans;

        // 結果の出力
        std::cout << "case " << fnum << ": ";
        if (ans == myans && time <= TIME_LIMIT) {
            std::cout << "OK" << std::endl;
        } else {
            std::cout << "NG" << std::endl;
            std::cout << "ans = " << ans << std::endl;
            std::cout << "myans = " << myans << std::endl;
            std::cout << "time = " << time << "[s]" << std::endl;
        }
    }

    return 0;
}
