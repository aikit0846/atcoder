    #include <iostream>
    #include <fstream>
    #include <ctime>
    #include <string>
    #include <vector>
    #include <cmath>

    const int F_NUM = 27;  // テストケースの数
    const int TIME_LIMIT = 2;  // 時間制限

    int main()
    {
        int fnum, myans, ans;
        int N, M, i, j, tmp, div, count;
        bool flag;
        double start;
        std::string in_path, out_path;

        for (fnum = 1; fnum <= F_NUM; fnum++) {
            // 標準入力をテストケースの入力ファイルに設定
            if (fnum < 10) {
                in_path = "in/0" + std::to_string(fnum) + ".txt";
            } else {
                in_path = "in/" + std::to_string(fnum) + ".txt";
            }
            std::ifstream in(in_path);
            std::cin.rdbuf(in.rdbuf());
            start = clock();

            // 標準入力
            std::cin >> N >> M;
            std::vector<int> k(M), p(M);
            std::vector<std::vector<int>> s(M, std::vector<int>(0));
            for (i = 0; i < M; i++) {
                std::cin >> k[i];
                for (j = 0; j < k[i]; j++) {
                    std::cin >> tmp;
                    s[i].emplace_back(tmp);
                }
            }
            for (i = 0; i < M; i++) {
                std::cin >> p[i];
            }

            // アルゴリズムの内容
            std::vector<int> bit(N);
            myans = 0;
            for (i = 0; i < std::pow(2, N); i++) {
                for (j = 0; j < N; j++) {
                    div = (1 << j);
                    bit[j] = (i / div) % 2;
                }

                flag = false;
                for (j = 0; j < M; j++) {
                    count = 0;
                    for (auto &&k : s[j]) {
                        count += bit[k - 1];
                    }
                    if (count % 2 != p[j]) {
                        break;
                    }
                    if (j == M - 1) {
                        flag = true;
                    }
                }

                if (flag) {
                    myans++;
                }
            }

            // 時間測定完了
            double time = (clock() - start) / CLOCKS_PER_SEC;

            // 標準入力をテストケースの出力ファイルに設定
            if (fnum < 10) {
                out_path = "out/0" + std::to_string(fnum) + ".txt";
            } else {
                out_path = "out/" + std::to_string(fnum) + ".txt";
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
                std::cout << "time = " << time << std::endl;
            }
        }

        return 0;
    }
