#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int i;
    long long N, right, left, center, ans;
    std::cin >> N;
    std::vector<int> H(N), S(N);
    std::vector<double> R(N);
    for (i = 0; i < N; i++) {
        std::cin >> H[i] >> S[i];
    }

    left = *std::max_element(H.begin(), H.end());
    right = left + *std::max_element(S.begin(), S.end()) * N;
    while (right > left + 1) {
        center = (left + right) / 2;
        for (i = 0; i < N; i++) {
            R[i] = (center - H[i]) / static_cast<double>(S[i]);
        }
        std::sort(R.begin(), R.end(), std::less<double>{});
        for (i = 0; i < N; i++) {
            if (R[i] < i) {
                left = center;
                break;
            }
            if (i == N - 1) {
                right = center;
            }
        }
    }

    center = (left + right) / 2;
    for (i = 0; i < N; i++) {
        R[i] = (center - H[i]) / static_cast<double>(S[i]);
    }
    std::sort(R.begin(), R.end(), std::less<double>{});
    for (i = 0; i < N; i++) {
        if (R[i] < i) {
            ans = right;
            break;
        }
        if (i == N - 1) {
            ans = left;
        }
    }
 
    std::cout << ans << std::endl;

    return 0;
}