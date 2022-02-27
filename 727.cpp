#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s1, string s2) {
        string ans;
        int cnt = 0;
        for (int i = 0; s1[i]; ++i) {
            if (s2[cnt] == s1[i]) ++cnt;
            if (cnt == s2.size()) {
                int left = i;
                while (cnt) {
                    if (s1[left] == s2[cnt - 1]) --cnt;
                    --left;
                }
                if (ans.size() == 0 || i - left < ans.size()) ans = s1.substr(left + 1, i - left);
                i = left + 1;
            }
        }
        return ans;
    }
};