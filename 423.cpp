#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  string ans;
  string ind[10]{"zero", "one", "two",   "three", "four",
                 "five", "six", "seven", "eight", "nine"};
  unordered_map<char, int> m;
  void check(char c, int i) {
    auto iter = m.find(c);
    if (iter != m.end()) {
      auto cnt = iter->second;
      for (auto ch : ind[i]) {
        m[ch] -= cnt;
        if (m[ch] == 0) m.erase(ch);
      }
      while (cnt--) {
        ans.push_back(i + '0');
      }
    }
  }

 public:
  string originalDigits(string s) {
    for (auto c : s) {
      ++m[c];
    }
    check('z', 0);
    check('x', 6);
    check('u', 4);
    check('f', 5);
    check('s', 7);
    check('g', 8);
    check('i', 9);
    check('w', 2);
    check('o', 1);
    check('t', 3);
    sort(ans.begin(), ans.end());
    return ans;
  }
};