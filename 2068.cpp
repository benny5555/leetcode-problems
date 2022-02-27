#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int n = word1.size();
        vector<int> cnt1(256), cnt2(256);
        for (int i = 0; i < n; ++i) {
            ++cnt1[word1[i]], ++cnt2[word2[i]];
        }
        for (int i = 0; i < 256; ++i) {
            if (abs(cnt1[i] - cnt2[i]) > 3) return false;
        }
        return true;
    }
};