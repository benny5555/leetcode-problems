#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int compress(vector<char>& chars) {
    if (chars.size() == 0) return 0;
    string s;
    char pre = chars[0];
    int prei = 0, n = chars.size();
    for (int i = 0; i <= n; ++i) {
      if (i == n || chars[i] != pre) {
        s += pre;
        s += i - prei > 1 ? to_string(i - prei) : "";
        pre = i == n ? 0 : chars[i];
        prei = i;
      }
    }
    chars = vector<char>(s.begin(), s.end());
    return s.size();
  }
};