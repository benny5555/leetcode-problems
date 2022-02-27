#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string &s, string &t) {
        int n = t.size();
        if (!n) return 0;
        vector<int> next(n);
        for (int i = 1, j = 0; t[i]; ++i) {
            while (j && t[i] != t[j]) j = next[j - 1];
            if (t[i] == t[j]) ++j;
            next[i] = j;
        }
        for (int i = 0, j = 0; s[i]; ++i) {
            while (j && s[i] != t[j]) j = next[j - 1];
            if (s[i] == t[j]) ++j;
            if (j == t.size()) return i - j + 1;
        }
        return -1;
    }
};