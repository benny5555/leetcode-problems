#include <bits/stdc++.h>
using namespace std;
/*1 <= s1.length, s2.length <= 40
s1 and s2 consist of digits 1-9 (inclusive), and lowercase English letters only.
The number of consecutive digits in s1 and s2 does not exceed 3.
:: xyz
x + y + z
xy + z
x + yz
xyz
40 / 4 = 10, 4^10 = 1e6*/

class Solution {
private:
    vector<vector<vector<bool>>> vis;

public:
    Solution() :
        vis(vector<vector<vector<bool>>>(41, vector<vector<bool>>(41, vector<bool>(2000)))) {
    }
    bool possiblyEquals(string &s1, string &s2, int i = 0, int j = 0, int diff = 0) {
        auto processDigits = [&](const string &s, int &p, int sign) {
            for (int val = 0; p < s.size() && isdigit(s[p]);) {
                val = val * 10 + s[p++] - '0';
                if (possiblyEquals(s1, s2, i, j, diff + val * sign)) return true;
            }
            return false;
        };
        if (i == s1.size() && j == s2.size()) return true;
        if (!vis[i][j][1000 + diff]) {
            vis[i][j][1000 + diff] = true;
            if (i < s1.size() && isdigit(s1[i])) {
                return processDigits(s1, i, -1);
            }
            if (j < s2.size() && isdigit(s2[j])) {
                return processDigits(s2, j, 1);
            }
            if (diff > 0) {
                return i < s1.size() && possiblyEquals(s1, s2, i + 1, j, diff - 1);
            }
            if (diff < 0) {
                return j < s2.size() && possiblyEquals(s1, s2, i, j + 1, diff + 1);
            }
            return i < s1.size() && j < s2.size() && s1[i] == s2[j] && possiblyEquals(s1, s2, i + 1, j + 1, diff);
        }
        return false;
    }
};
int main() {
    string s1 = "internationalization", s2 = "i18n";
    Solution solution;
    cout << solution.possiblyEquals(s1, s2) << endl;
    return 0;
}