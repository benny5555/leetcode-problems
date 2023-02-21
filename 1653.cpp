#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimumDeletions(string s) {
    int ans = 0, n = s.size();
    stack<char> stk;
    for (int i = n - 1; i >= 0; --i) {
      char c = s[i];
      if (stk.size() && stk.top() < c) {
        ++ans;
        stk.pop();
      } else {
        stk.push(c);
      }
    }
    return ans;
  }
};