#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

const int F_NUM = 9;  // テストケースの数
const int TIME_LIMIT = 2;  // 時間制限

int main()
{
    int fnum;
    long long ans, myans, tmp;
    int N, K, i, j, div, highest;
    double start;
    std::string in_path, out_path;

    for (fnum = 1; fnum <= F_NUM; fnum++) {
        // 標準入力をテストケースの入力ファイルに設定
        if (fnum <= 2) {
            in_path = "in/sub0_in" + std::to_string(fnum) + ".txt";
        } else if (fnum <= 4) {
            in_path = "in/sub1_in" + std::to_string(fnum - 2) + ".txt";
        } else if (fnum <= 7) {
            in_path = "in/sub2_in" + std::to_string(fnum - 4) + ".txt";
        } else {
            in_path = "in/sub3_in" + std::to_string(fnum - 7) + ".txt";
        }
        std::ifstream in(in_path);
        std::cin.rdbuf(in.rdbuf());
        start = clock();

        // 標準入力
        std::cin >> N >> K;
        std::vector<int> a(N);
        for (i = 0; i < N; i++) {
            std::cin >> a[i];
        }
        
        // アルゴリズムの内容
        std::vector<int> bit(N);
        myans = LLONG_MAX;
        for (i = 0; i < std::pow(2, N); i++) {
            for (j = 0; j < N; j++) {
                div = 1 << j;
                bit[j] = (i / div) % 2;
            }

            if (std::accumulate(bit.begin(), bit.end(), 0) < K) {
                continue;
            }
        
            highest = a[0];
            tmp = 0;
            for (j = 1; j < N; j++) {
                if (bit[j] == 1 && a[j] <= highest) {
                    tmp += (highest - a[j] + 1);
                    highest++;
                }
                if (a[j] > highest) {
                    highest = a[j];
                }
            }

            if (tmp < myans) {
                myans = tmp;
            }
        }

        // 時間測定完了
        double time = (clock() - start) / CLOCKS_PER_SEC;

        // 標準入力をテストケースの出力ファイルに設定
        if (fnum <= 2) {
            out_path = "out/sub0_in" + std::to_string(fnum) + ".txt";
        } else if (fnum <= 4) {
            out_path = "out/sub1_in" + std::to_string(fnum - 2) + ".txt";
        } else if (fnum <= 7) {
            out_path = "out/sub2_in" + std::to_string(fnum - 4) + ".txt";
        } else {
            out_path = "out/sub3_in" + std::to_string(fnum - 7) + ".txt";
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
