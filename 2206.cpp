#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool divideArray(vector<int>& nums) {
    int cnt[505]{0};
    for (int num : nums) {
      ++cnt[num];
    }
    for (int i = 0; i < 505; ++i) {
      if (cnt[i] % 2 != 0) return false;
    }
    return true;
  }
};