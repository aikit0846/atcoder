#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int strtoint(std::string s) {
    int i, res;
    
    res = 0;
    if (s[0] == '0') {
        res += (s[1] - '0') * 60 * 60;
    } else {
        res += std::stoi(s.substr(0, 2)) * 60 * 60;
    }
    if (s[3] == '0') {
        res += (s[4] - '0') * 60;
    } else {
        res += std::stoi(s.substr(3, 2)) * 60;
    }
    if (s[6] == '0') {
        res += s[7] - '0';
    } else {
        res += std::stoi(s.substr(6, 2));
    }

    return res;
}


int main()
{
    int n, hh, mm, ss, i, j, dep, arr;
    std::string depstr, arrstr;
    
    while (true) {
        std::cin >> n;
        if (!n) {
            break;
        }

        std::vector<int> add(60 * 60 * 24), num(60 * 60 * 24 + 1);

        for (i = 0; i < n; i++) {
            std::cin >> depstr >> arrstr;
            dep = strtoint(depstr);
            arr = strtoint(arrstr);
            add[dep]++;
            add[arr]--;
        }

        for (i = 0; i < 60 * 60 * 24; i++) {
            num[i + 1] = num[i] + add[i];
        }

        std::cout << *std::max_element(num.begin(), num.end()) << std::endl;
    }

    return 0;
}