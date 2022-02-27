#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; s[i]; ++i) {
            if (s[i] == 'I') {
                if (s[i + 1] == 'V' || s[i + 1] == 'X') {
                    ans += s[i + 1] == 'V' ? 4 : 9;
                    ++i;
                } else
                    ++ans;
            } else if (s[i] == 'X') {
                if (s[i + 1] == 'L' || s[i + 1] == 'C') {
                    ans += s[i + 1] == 'L' ? 40 : 90;
                    ++i;
                } else
                    ans += 10;
            } else if (s[i] == 'C') {
                if (s[i + 1] == 'D' || s[i + 1] == 'M') {
                    ans += s[i + 1] == 'D' ? 400 : 900;
                    ++i;
                } else
                    ans += 100;
            } else if (s[i] == 'V') {
                ans += 5;
            } else if (s[i] == 'L') {
                ans += 50;
            } else if (s[i] == 'D') {
                ans += 500;
            } else
                ans += 1000;
        }
        return ans;
    }
};