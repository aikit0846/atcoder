#include <iostream>
#include <string>

int main()
{
    std::string S;
    std::cin >> S;

    S[S.length() - 1] = '4';

    std::cout << S << std::endl;

    return 0;
}