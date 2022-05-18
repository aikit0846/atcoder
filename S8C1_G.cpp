#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <utility>

const int F_NUM = 9;  // テストケースの数
const int TIME_LIMIT = 2;  // 時間制限

int main()
{
    int fnum;
    int N, M, S, v, u, i, j;
    long long tmp, div, Sev, count, mymin, mynum, ansmin, ansnum;
    const long long INF = LLONG_MAX / 2;
    double start;
    std::string in_path, out_path, tmpans;

    for (fnum = 1; fnum <= F_NUM; fnum++) {
        // 標準入力をテストケースの入力ファイルに設定
        if (fnum <= 4) {
            in_path = "in/sample" + std::to_string(fnum) + ".txt";
        } else {
            in_path = "in/sub1_" + std::to_string(fnum - 4) + ".txt";
        }
        std::ifstream in(in_path);
        std::cin.rdbuf(in.rdbuf());
        start = clock();

        // 標準入力
        std::cin >> N >> M;
        std::vector<int> s(M), t(M);
        std::vector<long long> d(M), time(M);
        for (i = 0; i < M; i++) {
            std::cin >> s[i] >> t[i] >> d[i] >> time[i];
        }
        // std::cout << "aaa" << std::endl;

        // アルゴリズムの内容
        std::vector<std::vector<long long>> dis(N, std::vector<long long>(N, INF)), limit(N, std::vector<long long>(N, 0));
        std::vector<std::vector<long long>> dp(1 << N, std::vector<long long>(N, INF)), dp_num(1 << N, std::vector<long long>(N, 0));

        for (i = 0; i < M; i++) {
            dis[s[i] - 1][t[i] - 1] = d[i];
            dis[t[i] - 1][s[i] - 1] = d[i];
            limit[s[i] - 1][t[i] - 1] = time[i];
            limit[t[i] - 1][s[i] - 1] = time[i];
        }
        // std::cout << "aaa" << std::endl;
        dp[0][0] = 0;
        dp_num[0][0] = 1;
        for (S = 0; S < 1 << N; S++) {
            // std::cout << "aaa" << std::endl;
            for (v = 0; v < N; v++) {
                if (S & (1 << v)) {
                    continue;
                }
                tmp = INF;
                count = 0;
                for (u = 0; u < N; u++) {
                    if (S != 0 && !(S & (1 << u))) {
                        continue;
                    }
                    if (dp[S][u] + dis[u][v] <= limit[u][v]) {
                        if (dp[S][u] + dis[u][v] == tmp) {
                            count += dp_num[S][u];
                            continue;
                        }
                        if (dp[S][u] + dis[u][v] < tmp) {
                            count = dp_num[S][u];
                            tmp = dp[S][u] + dis[u][v];
                        }
                    }
                }
                dp[S | (1 << v)][v] = tmp;
                dp_num[S | (1 << v)][v] = count;
            }
        }
        // std::cout << dp[1][0] << std::endl;

        mymin = dp[(1 << N) - 1][0];
        mynum = dp_num[(1 << N) - 1][0];

        // 時間測定完了
        double duration = (clock() - start) / CLOCKS_PER_SEC;

        // 標準入力をテストケースの出力ファイルに設定
        if (fnum <= 4) {
            out_path = "out/sample" + std::to_string(fnum) + ".txt";
        } else {
            out_path = "out/sub1_" + std::to_string(fnum - 4) + ".txt";
        }
        std::ifstream out(out_path);
        std::cin.rdbuf(out.rdbuf());
        
        // 標準入力（答えの入力）
        std::cin >> tmpans;
        if (tmpans == "IMPOSSIBLE") {
            ansmin = INF;
            ansnum = 0;
        } else {
            ansmin = std::stoll(tmpans);
            std::cin >> ansnum;
        }

        // 結果の出力
        std::cout << "case " << fnum << ": ";
        if (mymin == ansmin && mynum == ansnum && duration <= TIME_LIMIT) {
            std::cout << "OK" << std::endl;
        } else {
            std::cout << "NG" << std::endl;
            std::cout << "ans = " << ansmin << " " << ansnum << std::endl;
            std::cout << "myans = " << mymin << " " << mynum << std::endl;
            std::cout << "time = " << duration << "[s]" << std::endl;
        }
    }

    return 0;
}
