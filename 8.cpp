#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        auto start = s.find_first_not_of(" ");
        if (start == s.npos) return 0;
        if (s[start] != '-' && s[start] != '+' && !isdigit(s[start])) return 0;
        int special = -1;
        if (!isdigit(s[start])) {
            if (s[start] == '-') special = start;
            ++start;
        }
        if (start >= s.size() || !isdigit(s[start])) return 0;
        int end = start;
        while (end < s.size() && isdigit(s[end])) ++end;
        string temp = s.substr(start, end - start);
        for (int i = 0; temp[i]; ++i) {
            ans = ans * 10 + temp[i] - '0';
            if (ans > INT_MAX) {
                if (special != -1)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
        }
        if (special != -1) ans = -ans;
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        return ans;
    }
};