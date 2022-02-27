#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        string ans = to_string(x);
        for (int i = 0, j = ans.size() - 1; i < j; ++i, --j) {
            if (ans[i] != ans[j]) return false;
        }
        return true;
    }
};