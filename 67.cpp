#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    for (int i = a.size() - 1, j = b.size() - 1, flag = 0;
         i >= 0 || j >= 0 || flag; --i, --j) {
      int x = i >= 0 ? a[i] - '0' : 0, y = j >= 0 ? b[j] - '0' : 0;
      int temp = x + y + flag;
      flag = 0;
      if (temp > 1) {
        flag = temp / 2;
        temp %= 2;
      }
      ans.push_back(temp + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};