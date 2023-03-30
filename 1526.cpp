#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minNumberOperations(vector<int>& target) {
    int ans = target.front();
    for (int i = 1; i < target.size(); ++i) {
      ans += max(target[i] - target[i - 1], 0);
    }
    return ans;
  }
};