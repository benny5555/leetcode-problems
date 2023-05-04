#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int arraySign(vector<int>& nums) {
    int cnt = 0;
    for (auto x : nums) {
      if (x == 0) return 0;
      if (x < 0) ++cnt;
    }
    return (cnt & 1) ? -1 : 1;
  }
};