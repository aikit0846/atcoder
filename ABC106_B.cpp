#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

int main()
{
    int num, ti, count, N, i, j, myans, ans;
    std::string in_path, out_path;

    for (num = 1; num <= 11; num++) {
        if (num < 10) {
            in_path = "in/in0" + std::to_string(num) + ".txt";
        } else {
            in_path = "in/in" + std::to_string(num) + ".txt";
        }

        std::ifstream in(in_path);
        std::cin.rdbuf(in.rdbuf());
        ti = clock();
        std::cin >> N;

        myans = 0;
        for (i = 1; i <= N; i += 2) {
            count = 0;
            for (j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    count++;
                }
            }
            if (count == 4) {
                myans++;
            }
        }

        if (num < 10) {
            out_path = "out/in0" + std::to_string(num) + ".txt";
        } else {
            out_path = "out/in" + std::to_string(num) + ".txt";
        }

        std::ifstream out(out_path);
        std::cin.rdbuf(out.rdbuf());
        std::cin >> ans;

        double time = (clock() - ti) / CLOCKS_PER_SEC;

        std::cout << "case " << num << ": ";
        if (ans == myans && time <= 2) {
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
