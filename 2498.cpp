#include <bits/stdc++.h>
using namespace std;
/*
1. We must make use of all rocks
2. Optimal solution can never use consecutive two rocks.
*/
class Solution {
 public:
  int maxJump(vector<int>& stones) {
    int ans = stones[1] - stones[0];
    for (int i = 2; i < stones.size(); ++i) {
      ans = max(ans, stones[i] - stones[i - 2]);
    }
    return ans;
  }
};