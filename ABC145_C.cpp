    #include <iostream>
    #include <fstream>
    #include <ctime>
    #include <string>
    #include <vector>
    #include <cmath>

    const int F_NUM = 14;  // テストケースの数
    const int TIME_LIMIT = 2;  // 時間制限

    int main()
    {
        int fnum;
        double ans, myans;
        int N, i, j, count;
        double start;
        std::string in_path, out_path;

        for (fnum = 0; fnum <= F_NUM; fnum++) {
            // 標準入力をテストケースの入力ファイルに設定
            if (fnum <= 2) {
                in_path = "in/sample0" + std::to_string(fnum) + ".txt";
            } else if (fnum <= 5) {
                in_path = "in/handmade0" + std::to_string(fnum) + ".txt";
            } else if (fnum <= 9) {
                in_path = "in/random0" + std::to_string(fnum) + ".txt";
            } else {
                in_path = "in/random" + std::to_string(fnum) + ".txt";
            }
            std::ifstream in(in_path);
            std::cin.rdbuf(in.rdbuf());
            start = clock();

            // 標準入力
            std::cin >> N;
            std::vector<int> x(N), y(N), P(N);
            for (i = 0; i < N; i++) {
                std::cin >> x[i] >> y[i];
                P[i] = i;
            }

            // アルゴリズムの内容
            myans = 0;
            count = 0;
            do {
                for (i = 0; i < N - 1; i++) {
                    myans += std::sqrt((x[P[i + 1]] - x[P[i]]) * (x[P[i + 1]] - x[P[i]]) + (y[P[i + 1]] - y[P[i]]) * (y[P[i + 1]] - y[P[i]]));
                }
                count++;
            } while (std::next_permutation(P.begin(), P.end()));
            myans /= count;

            // 時間測定完了
            double time = (clock() - start) / CLOCKS_PER_SEC;

            // 標準入力をテストケースの出力ファイルに設定
            if (fnum <= 2) {
                out_path = "out/sample0" + std::to_string(fnum) + ".txt";
            } else if (fnum <= 5) {
                out_path = "out/handmade0" + std::to_string(fnum) + ".txt";
            } else if (fnum <= 9) {
                out_path = "out/random0" + std::to_string(fnum) + ".txt";
            } else {
                out_path = "out/random" + std::to_string(fnum) + ".txt";
            }
            std::ifstream out(out_path);
            std::cin.rdbuf(out.rdbuf());
            
            // 標準入力（答えの入力）
            std::cin >> ans;

            // 結果の出力
            std::cout << "case " << fnum << ": ";
            if ((std::abs(ans - myans) <= 0.000001 || std::abs(ans - myans) / ans <= 0.000001) && time <= TIME_LIMIT) {
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
