#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
// #include <fstream>

int main()
{
    int w, h, i, j, k, ans, r, s, rh, rw, ih, iw, sh, sw;
    // std::string path = "in1.txt";
    // std::ifstream in(path);
    // std::cin.rdbuf(in.rdbuf());

    while (true) {
        std::cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }
        std::vector<std::vector<int>> c(h, std::vector<int>(w));
        std::vector<std::vector<int>> list(h * w);
        std::vector<int> done(h * w, 1);
        std::stack<int> st;
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                std::cin >> c[i][j];
            }
        }
        for (i = 0; i < h * w; i++) {
            ih = i / w;
            iw = i % w;
            if (c[ih][iw] == 0) {
                done[i] = 0;
                continue;
            }
            for (j = ih - 1; j <= ih + 1; j++) {
                for (k = iw - 1; k <= iw + 1; k++) {
                    if (j < 0 || k < 0 || j >= h || k >= w) {
                        continue;
                    }
                    if (c[j][k] == 1) {
                        list[i].emplace_back(j * w + k);
                    }
                }
            }
        }

        ans = 0;
        while (true) {
            auto itr = std::find(done.begin(), done.end(), 1);
            if (itr == done.end()) {
                break;
            }
            r = itr - done.begin();
            done[r] = 2;
            st.push(r);

            while (st.size() > 0) {
                r = st.top();
                st.pop();

                for (auto &&s : list[r]) {
                    if (done[s] != 2) {
                        done[s] = 2;
                        st.push(s);
                    }
                }
            }
            ans++;
        }

        std::cout << ans << std::endl;
    }

    return 0;
}