#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maximumBags(vector<int>& capacity, vector<int>& rocks,
                  int additionalRocks) {
    vector<int> v;
    for (int i = 0; i < capacity.size(); ++i) {
      v.push_back(capacity[i] - rocks[i]);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (auto left : v) {
      if (left == 0 || additionalRocks >= left) {
        ++ans;
        additionalRocks -= left;
      }
    }
    return ans;
  }
};