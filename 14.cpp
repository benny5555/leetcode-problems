#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string &temp = strs[0];
        int size = temp.size();
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            for (; strs[i][j]; ++j) {
                if (strs[i][j] != temp[j]) break;
            }
            if (!j) return "";
            size = min(size, j);
        }
        return temp.substr(0, size);
    }
};

int main() {
    vector<string> v{
        "aaa", "aa", "aaa"};
    Solution solution;
    solution.longestCommonPrefix(v);
    return 0;
}