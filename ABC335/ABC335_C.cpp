#include <iostream>
#include <vector>

int main()
{
    int N, Q, i, q1, x, y, moveNum;
    std::cin >> N >> Q;
    std::vector<std::vector<int>> partsOne;

    x = 1;
    y = 0;
    moveNum = 0;
    std::vector<int> initPartsOne = {x, y};
    partsOne.emplace_back(initPartsOne);
    for (i = 0; i < Q; i++) {
        std::cin >> q1;
        if (q1 == 1) {
            char q2;
            std::cin >> q2;
            switch (q2) {
                case 'R':
                x++;
                break;
                case 'L':
                x--;
                break;
                case 'U':
                y++;
                break;
                case 'D':
                y--;
                break;
            }
            std::vector<int> tmpPartsOne = {x, y};
            partsOne.emplace_back(tmpPartsOne);
            moveNum++;
        } else {
            int q2;
            std::cin >> q2;
            if (q2 > moveNum) {
                std::cout << q2 - moveNum << " " << 0 << std::endl;
            } else {
                std::cout << partsOne[moveNum - q2 + 1][0] << " " << partsOne[moveNum - q2 + 1][1] << std::endl;
            }
        }
    }

    return 0;
}