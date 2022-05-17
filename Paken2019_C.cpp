#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>

const int F_NUM = 20;  // テストケースの数
const int TIME_LIMIT = 1;  // 時間制限

int main()
{
    int fnum;
    int N, M, i, j, k;
    long long myans, ans, tmp;
    double start;
    std::string in_path, out_path;

    for (fnum = 1; fnum <= F_NUM; fnum++) {
        // 標準入力をテストケースの入力ファイルに設定
        if (fnum <= 3) {
            in_path = "in/sample_0" + std::to_string(fnum) + ".txt";
        } else if (fnum <= 7) {
            in_path = "in/sub1_in0" + std::to_string(fnum - 3) + ".txt";
        } else if (fnum <= 11) {
            in_path = "in/sub2_in0" + std::to_string(fnum - 7) + ".txt";
        } else if (fnum <= 15) {
            in_path = "in/sub3_in0" + std::to_string(fnum - 11) + ".txt";
        } else {
            in_path = "in/sub4_in0" + std::to_string(fnum - 15) + ".txt";
        }
        std::ifstream in(in_path);
        std::cin.rdbuf(in.rdbuf());
        start = clock();

        // 標準入力
        std::cin >> N >> M;
        std::vector<std::vector<int>> A(N, std::vector<int>(M));
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                std::cin >> A[i][j];
            }
        }

        // アルゴリズムの内容
        myans = 0;
        for (i = 0; i < M; i++) {
            for (j = i + 1; j < M; j++) {
                tmp = 0;
                for (k = 0; k < N; k++) {
                    tmp += std::max(A[k][i], A[k][j]);
                }
                if (tmp > myans) {
                    myans = tmp;
                }
            }
        }

        // 時間測定完了
        double time = (clock() - start) / CLOCKS_PER_SEC;

        // 標準入力をテストケースの出力ファイルに設定
        if (fnum <= 3) {
            out_path = "out/sample_0" + std::to_string(fnum) + ".txt";
        } else if (fnum <= 7) {
            out_path = "out/sub1_in0" + std::to_string(fnum - 3) + ".txt";
        } else if (fnum <= 11) {
            out_path = "out/sub2_in0" + std::to_string(fnum - 7) + ".txt";
        } else if (fnum <= 15) {
            out_path = "out/sub3_in0" + std::to_string(fnum - 11) + ".txt";
        } else {
            out_path = "out/sub4_in0" + std::to_string(fnum - 15) + ".txt";
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
