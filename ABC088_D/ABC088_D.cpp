#include <iostream>
#include <vector>
#include <queue>


int twoDtoOneD(int idx1, int idx2, int H, int W)
{
    return idx1 * W + idx2;
}


int main()
{
    int H, W, i, j, idx1, idx2, oneDIdx, whiteCount;
    std::cin >> H >> W;
    std::vector<std::vector<bool>> s(H, std::vector<bool>(W, false));
    char tmp;
    whiteCount = -2;
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            std::cin >> tmp;
            if (tmp == '.') {
                s[i][j] = true;
                whiteCount++;
            }
        }
    }

    std::queue<int> que;
    std::vector<std::vector<int>> paintCount(H, std::vector<int>(W, -2));
    
    que.push(twoDtoOneD(0, 0, H, W));
    paintCount[0][0] = whiteCount;
    while (!que.empty()) {
        oneDIdx = que.front();
        que.pop();
        idx1 = oneDIdx / W;
        idx2 = oneDIdx % W;

        if (idx1 > 0 && s[idx1 - 1][idx2]) {
            if (paintCount[idx1][idx2] - 1 > paintCount[idx1 - 1][idx2]) {
                paintCount[idx1 - 1][idx2] = paintCount[idx1][idx2] - 1;
                que.push(twoDtoOneD(idx1 - 1, idx2, H, W));
            }
        }
        if (idx1 < H - 1 && s[idx1 + 1][idx2]) {
            if (paintCount[idx1][idx2] - 1 > paintCount[idx1 + 1][idx2]) {
                paintCount[idx1 + 1][idx2] = paintCount[idx1][idx2] - 1;
                que.push(twoDtoOneD(idx1 + 1, idx2, H, W));
            }
        }
        if (idx2 > 0 && s[idx1][idx2 - 1]) {
            if (paintCount[idx1][idx2] - 1 > paintCount[idx1][idx2 - 1]) {
                paintCount[idx1][idx2 - 1] = paintCount[idx1][idx2] - 1;
                que.push(twoDtoOneD(idx1, idx2 - 1, H, W));
            }
        }
        if (idx2 < W - 1 && s[idx1][idx2 + 1]) {
            if (paintCount[idx1][idx2] - 1 > paintCount[idx1][idx2 + 1]) {
                paintCount[idx1][idx2 + 1] = paintCount[idx1][idx2] - 1;
                que.push(twoDtoOneD(idx1, idx2 + 1, H, W));
            }
        }
    }

    std::cout << paintCount[H - 1][W - 1] + 1 << std::endl;

    return 0;
}