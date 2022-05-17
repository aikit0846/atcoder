#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, i;
    long long ans;
    std::cin >> N;
    std::vector<int> A(N), B(N), C(N);
    for (i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (i = 0; i < N; i++) {
        std::cin >> B[i];
    }
    for (i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    std::sort(A.begin(), A.end());
    std::sort(C.begin(), C.end());

    ans = 0;
    for (i = 0; i < N; i++) {
        auto aitr = std::lower_bound(A.begin(), A.end(), B[i]);
        auto citr = std::upper_bound(C.begin(), C.end(), B[i]);
        if (B[i] > *(A.end() - 1)) {
            aitr = A.end();
        }
        if (B[i] < *C.begin()) {
            citr = C.begin();
        }
        ans += ((aitr - A.begin()) * (C.end() - citr));
    }

    std::cout << ans << std::endl;

    return 0;
}