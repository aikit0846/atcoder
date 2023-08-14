#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string S;
    int ans, head, i, counter;
    std::cin >> S;

    ans = 0;
    for (head = 0; head < S.length(); head++) {
        counter = 0;
        for (i = head; i < S.length(); i++) {
            if (S[i] != 'A' && S[i] != 'C' && S[i] != 'G' && S[i] != 'T') {
                break;
            }
            counter++;
        }

        ans = std::max(ans, counter);
    }

    std::cout << ans << std::endl;

    return 0;
}