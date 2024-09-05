// LC_1945.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//int getLucky(string s, int k) {
//    string numStr;
//    int res = 0;
//    for (const auto c : s) {
//        int pos = c - 'a' + 1;
//        numStr += to_string(pos);
//    }
//    for (const auto c : numStr) {
//        res += c - '0';
//    }
//    for (int i = 1; i < k; i++) {
//        int temp = 0;
//        while (res > 0) {
//            temp += res % 10;
//            res /= 10;
//        }
//        res = temp;
//    }
//    return res;
//}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        unsigned int answer = 0;
        int loop = 0;

        for (int i = 0; i < s.size(); i++) {
            int convert = s[i] - 96;
            answer += convert;
        }
        s.clear();
        s += to_string(answer);

        while (loop + 1 <= k) {
            answer = 0;
            for (int i = 0; i < s.size(); i++) {
                int convert = s[i] - 48;
                
                answer += convert;
            }
            s.clear();
            s += to_string(answer);
            loop++;
        }

        cout << answer << endl;
        return answer;
    }
};

int main()
{
    Solution sol;

    string s = "leetcode";
    int k = 2;

    sol.getLucky(s, k);
}

