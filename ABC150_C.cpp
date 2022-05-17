    #include <iostream>
    #include <fstream>
    #include <ctime>
    #include <string>
    #include <vector>

    const int F_NUM = 9;  // テストケースの数
    const int TIME_LIMIT = 2;  // 時間制限

    int main()
    {
        int fnum, myans, ans;
        int N, i, j, a, b, count;
        bool pflag, qflag;
        double start;
        std::string in_path, out_path;

        for (fnum = 1; fnum <= F_NUM; fnum++) {
            // 標準入力をテストケースの入力ファイルに設定
            if (fnum < 10) {
                in_path = "in/testcase_" + std::to_string(fnum) + ".txt";
            } else {
                in_path = "in/in" + std::to_string(fnum) + ".txt";
            }
            std::ifstream in(in_path);
            std::cin.rdbuf(in.rdbuf());
            start = clock();

            // 標準入力
            std::cin >> N;
            std::vector<int> P(N), Q(N);
            for (i = 0; i < N; i++) {
                std::cin >> P[i];
            }
            for (i = 0; i < N; i++) {
                std::cin >> Q[i];
            }

            // アルゴリズムの内容
            std::vector<int> C(N);
            for (i = 0; i < N; i++) {
                C[i] = i + 1;
            }

            count = 0;
            do {
                pflag = qflag = true;
                count++;
                for (i = 0; i < N; i++) {
                    if (C[i] != P[i]) {
                        pflag = false;
                    }
                    if (C[i] != Q[i]) {
                        qflag = false;
                    }
                }
                if (pflag) {
                    a = count;
                }
                if (qflag) {
                    b = count;
                }
            } while (std::next_permutation(C.begin(), C.end()));
            myans = std::abs(a - b);

            // 時間測定完了
            double time = (clock() - start) / CLOCKS_PER_SEC;

            // 標準入力をテストケースの出力ファイルに設定
            if (fnum < 10) {
                out_path = "out/testcase_" + std::to_string(fnum) + ".txt";
            } else {
                out_path = "out/in" + std::to_string(fnum) + ".txt";
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