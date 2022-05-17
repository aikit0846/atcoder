#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <stack>
#include <set>

const int F_NUM = 17;  // テストケースの数
const int TIME_LIMIT = 2;  // 時間制限

int main()
{
    int fnum;
    int N, Q, i, j, k, a, b, cur, n;
    double start;
    std::string in_path, out_path;

    for (fnum = 1; fnum <= F_NUM; fnum++) {
        // 標準入力をテストケースの入力ファイルに設定
        if (fnum <= 2) {
            in_path = "in/a0" + std::to_string(fnum) + ".txt";
        } else if (fnum <= 9) {
            in_path = "in/b0" + std::to_string(fnum) + ".txt";
        } else if (fnum <= 14) {
            in_path = "in/b" + std::to_string(fnum) + ".txt";
        } else {
            in_path = "in/after_contest_" + std::to_string(fnum) + ".txt";
        }
        std::ifstream in(in_path);
        std::cin.rdbuf(in.rdbuf());
        start = clock();

        // 標準入力
        std::cin >> N >> Q;
        std::vector<std::vector<int>> G(N);
        std::vector<int> p(Q), x(Q);
        for (i = 0; i < N - 1; i++) {
            std::cin >> a >> b;
            G[a - 1].emplace_back(b - 1);
        }
        for (i = 0; i < Q; i++) {
            std::cin >> p[i] >> x[i];
        }

        // アルゴリズムの内容
        std::vector<int> counter(N);
        std::stack<int> stack;
        std::vector<bool> seen(N, false);
        std::vector<int> add(N);

        for (i = 0; i < Q; i++) {
            add[p[i] - 1] += x[i];
        }

        stack.push(0);
        counter[0] += add[0];
        seen[0] = true;
        while (stack.size() != 0) {
            cur = stack.top();
            stack.pop();

            for (auto &&n : G[cur]) {
                counter[n] += (counter[cur] + add[n]);
                if (!seen[n]) {
                    stack.push(n);
                    seen[n] = true;
                }
            }
        }

        // 時間測定完了
        double time = (clock() - start) / CLOCKS_PER_SEC;

        // 標準入力をテストケースの出力ファイルに設定
        if (fnum <= 2) {
            out_path = "out/a0" + std::to_string(fnum) + ".txt";
        } else if (fnum <= 9) {
            out_path = "out/b0" + std::to_string(fnum) + ".txt";
        } else if (fnum <= 14) {
            out_path = "out/b" + std::to_string(fnum) + ".txt";
        } else {
            out_path = "out/after_contest_" + std::to_string(fnum) + ".txt";
        }
        std::ifstream out(out_path);
        std::cin.rdbuf(out.rdbuf());
        
        // 標準入力（答えの入力）
        std::vector<int> ans(N);
        for (i = 0; i < N; i++) {
            std::cin >> ans[i];
        }

        // 結果の出力
        std::cout << "case " << fnum << ": ";
        if (time > TIME_LIMIT) {
            std::cout << "NG" << std::endl;
            std::cout << "time = " << time << "[s]" << std::endl;
            return 0;
        }
        for (i = 0; i < N; i++) {
            if (counter[i] != ans[i]) {
                std::cout << "NG" << std::endl;
                // for (j = 0; j < N; j++) {
                //     std::cout << counter[j] << " " << ans[j] << std::endl;
                // }
                break;
            }
            if (i == N - 1) {
                std::cout << "OK" << std::endl;
            }
        }
    }

    return 0;
}
