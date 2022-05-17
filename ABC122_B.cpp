#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

const int F_NUM = 13;  // テストケースの数
const int TIME_LIMIT = 2;  // 時間制限

int main()
{
    int fnum, ans, myans;
    std::string S, tmp;
    int i, j;
    double start;
    std::string in_path, out_path;

    for (fnum = 1; fnum <= F_NUM; fnum++) {
        // 標準入力をテストケースの入力ファイルに設定
        if (fnum <= 3) {
            in_path = "in/a0" + std::to_string(fnum) + ".txt";
        } else if (fnum <= 9) {
            in_path = "in/b0" + std::to_string(fnum) + ".txt";
        } else {
            in_path = "in/b" + std::to_string(fnum) + ".txt";
        }
        std::ifstream in(in_path);
        std::cin.rdbuf(in.rdbuf());
        start = clock();

        // 標準入力
        std::cin >> S;

        // アルゴリズムの内容
        myans = 0;
        for (i = 0; i < S.size(); i++) {
            if (i + myans >= S.size()) {
                break;
            }
            tmp = "";
            for (j = i; j < S.size(); j++) {
                if (S[j] != 'A' && S[j] != 'C' && S[j] != 'G' && S[j] != 'T') {
                    break;
                }
                tmp += S[j];
            }
            if (tmp.size() > myans) {
                myans = tmp.size();
            }
        }

        // 時間測定完了
        double time = (clock() - start) / CLOCKS_PER_SEC;

        // 標準入力をテストケースの出力ファイルに設定
        if (fnum <= 3) {
            out_path = "out/a0" + std::to_string(fnum) + ".txt";
        } else if (fnum <= 9) {
            out_path = "out/b0" + std::to_string(fnum) + ".txt";
        } else {
            out_path = "out/b" + std::to_string(fnum) + ".txt";
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
