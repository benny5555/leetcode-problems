#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int getMaximumConsecutive(vector<int>& coins) {
    sort(coins.begin(), coins.end());
    int ans = 1;
    for (int c : coins) {
      if (c > ans) break;
      ans += c;
    }
    return ans;
  }
};