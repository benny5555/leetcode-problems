#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> m;
    for (auto num : tasks) {
      ++m[num];
    }
    int ans = 0;
    for (auto iter : m) {
      if (iter.second == 1) return -1;
      // 3k: need k, 3k+1 = 3(k-1)+2+2 [k+1], 3k+2[k+1];
      ans += (iter.second + 2) / 3;
    }
    return ans;
  }
};