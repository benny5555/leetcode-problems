#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> addToArrayForm(vector<int>& num, int k) {
    vector<int> ans, K;
    for (int i = num.size() - 1, flag = 0; i >= 0 || flag || k; --i, k /= 10) {
      int x = i >= 0 ? num[i] : 0, y = k % 10;
      int temp = x + y + flag;
      flag = 0;
      if (temp >= 10) {
        flag = 1;
        temp %= 10;
      }
      ans.push_back(temp);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};