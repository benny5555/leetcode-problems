#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int countAsterisks(string s) {
    bool star = true;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (c == '|') {
        if (star) {
          star = false;
        } else {
          star = true;
        }
      } else if (star && c == '*') {
        cout << i << endl;
        ++ans;
      }
    }
    return ans;
  }
};