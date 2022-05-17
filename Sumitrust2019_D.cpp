#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

const int F_NUM = 33;  // テストケースの数
const int TIME_LIMIT = 2;  // 時間制限

int main()
{
    int fnum, myans, ans;
    int N, i, j, c_idx, d_idx, e_idx;
    char c, d, e;
    bool is_ok;
    std::string S, pass;
    double start;
    std::string in_path, out_path;

    for (fnum = 1; fnum <= F_NUM; fnum++) {
        // 標準入力をテストケースの入力ファイルに設定
        if (fnum <= 3) {
            in_path = "in/00-sample-0" + std::to_string(fnum) + ".txt";
        } else if (fnum <= 7) {
            in_path = "in/01-corner-0" + std::to_string(fnum - 3) + ".txt";
        } else if (fnum <= 14) {
            in_path = "in/02-random-0" + std::to_string(fnum - 7) + ".txt";
        } else if (fnum <= 17) {
            in_path = "in/03-random-x-0" + std::to_string(fnum - 14) + ".txt";
        } else if (fnum <= 25) {
            in_path = "in/04-expand-0" + std::to_string(fnum - 17) + ".txt";
        } else {
            in_path = "in/05-limiting-0" + std::to_string(fnum - 25) + ".txt";
        }
        std::ifstream in(in_path);
        std::cin.rdbuf(in.rdbuf());
        start = clock();

        // 標準入力
        std::cin >> N;
        std::cin >> S;

        // アルゴリズムの内容
        myans = 0;
        for (c = '0'; c <= '9'; c++) {
            for (d = '0'; d <= '9'; d++) {
                for (e = '0'; e <= '9'; e++) {
                    is_ok = true;
                    for (i = 0; i < N; i++) {
                        if (S[i] == c) {
                            c_idx = i;
                            break;
                        }
                        if (i == N - 1) {
                            is_ok = false;
                        }
                    }
                    if (!is_ok) {
                        continue;
                    }

                    for (i = 0; i < N; i++) {
                        if (S[i] == d && i > c_idx) {
                            d_idx = i;
                            break;
                        }
                        if (i == N - 1) {
                            is_ok = false;
                        }
                    }
                    if (!is_ok) {
                        continue;
                    }          
                    
                    for (i = 0; i < N; i++) {
                        if (S[i] == e && i > d_idx) {
                            e_idx = i;
                            break;
                        }
                        if (i == N - 1) {
                            is_ok = false;
                        }
                    }
                    if (!is_ok) {
                        continue;
                    }

                    myans++;                       
                }
            }
        }

        // 時間測定完了
        double time = (clock() - start) / CLOCKS_PER_SEC;

        // 標準入力をテストケースの出力ファイルに設定
        if (fnum <= 3) {
            out_path = "out/00-sample-0" + std::to_string(fnum) + ".txt";
        } else if (fnum <= 7) {
            out_path = "out/01-corner-0" + std::to_string(fnum - 3) + ".txt";
        } else if (fnum <= 14) {
            out_path = "out/02-random-0" + std::to_string(fnum - 7) + ".txt";
        } else if (fnum <= 17) {
            out_path = "out/03-random-x-0" + std::to_string(fnum - 14) + ".txt";
        } else if (fnum <= 25) {
            out_path = "out/04-expand-0" + std::to_string(fnum - 17) + ".txt";
        } else {
            out_path = "out/05-limiting-0" + std::to_string(fnum - 25) + ".txt";
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
