#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.rbegin(), satisfaction.rend());
    int ans = 0, total = 0, n = satisfaction.size();
    for (int i = 0; i < n && satisfaction[i] > -total; ++i) {
      total += satisfaction[i];
      ans += total;
    }
    return ans;
  }
};