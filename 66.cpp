#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> ans;
    int temp = digits.back() + 1;
    bool flag = 0;
    if (temp > 9) {
      flag = 1;
      temp -= 10;
    }
    ans.push_back(temp);
    for (int i = digits.size() - 2; i >= 0 || flag; --i) {
      int x = i >= 0 ? digits[i] : 0;
      temp = x + flag;
      if (temp > 9) {
        temp -= 10;
        flag = 1;
      } else
        flag = 0;
      ans.push_back(temp);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};