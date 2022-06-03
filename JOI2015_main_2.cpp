#include <iostream>
#include <vector>
#include <algorithm>

long long circle(long long a, long long N) {
    if (a >= N) {
        do {
            a -= N;
        } while (a >= N);
    } else if (a < 0) {
        do {
            a += N;
        } while (a < 0);
    }

    return a;
}

int main()
{
    long long N, i, k, kukan, tmp, ans;
    std::cin >> N;
    std::vector<long long> A(N);
    for (i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<long long> > dp(N, std::vector<long long>(N));

    for (i = 0; i < N; i++) {
        dp[i][i] = A[i];
    }
    if (N == 1) {
        std::cout << dp[0][0] << std::endl;
        return 0;
    }
    for (i = 0; i < N; i++) {
        dp[i][circle(i + 1, N)] = std::max(A[i], A[circle(i + 1, N)]);
    }
    if (N == 2) {
        std::cout << dp[0][1] << std::endl;
        return 0;
    }

    for (kukan = 2; kukan < N - 1; kukan++) {
        for (i = 0; i < N; i++) {
            tmp = 0;
            if (A[circle(i + 1, N)] > A[circle(i + kukan, N)] && tmp < A[i] + dp[circle(i + 2, N)][circle(i + kukan, N)]) {
                tmp = A[i] + dp[circle(i + 2, N)][circle(i + kukan, N)];
            } else if (A[circle(i + 1, N)] < A[circle(i + kukan, N)] && tmp < A[i] + dp[circle(i + 1, N)][circle(i + kukan - 1, N)]) {
                tmp = A[i] + dp[circle(i + 1, N)][circle(i + kukan - 1, N)];
            }
            if (A[circle(i + kukan - 1, N)] > A[i] && tmp < A[circle(i + kukan, N)] + dp[i][circle(i + kukan - 2, N)]) {
                tmp = A[circle(i + kukan, N)] + dp[i][circle(i + kukan - 2, N)];
            } else if (A[i] > A[circle(i + kukan - 1, N)] && tmp < A[circle(i + kukan, N)] + dp[circle(i + 1, N)][circle(i + kukan - 1, N)]) {
                tmp = A[circle(i + kukan, N)] + dp[circle(i + 1, N)][circle(i + kukan - 1, N)];
            }
            dp[i][circle(i + kukan, N)] = tmp;
        }
    }

    ans = 0;
    for (k = 0; k < N; k++) {
        if (A[circle(k - 1, N)] > A[circle(k + 1, N)]) {
            if (ans < A[k] + dp[circle(k + 1, N)][circle(k - 2, N)]) {
                ans = A[k] + dp[circle(k + 1, N)][circle(k - 2, N)];
            }
        } else {
            if (ans < A[k] + dp[circle(k + 2, N)][circle(k - 1, N)]) {
                ans = A[k] + dp[circle(k + 2, N)][circle(k - 1, N)];
            }
        }
    }
    
    std::cout << ans << std::endl;

    return 0;
}