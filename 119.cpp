#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex + 1);
    for (int i = 0; i <= rowIndex; ++i) {
      auto temp = ans;
      ans[0] = ans[i] = 1;
      for (int j = 1; j < i; ++j) {
        ans[j] = temp[j - 1] + temp[j];
      }
    }
    return ans;
  }
};