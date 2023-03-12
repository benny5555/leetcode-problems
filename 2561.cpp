#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long minCost(vector<int>& basket1, vector<int>& basket2) {
    map<int, int> m;
    for (auto x : basket1) {
      ++m[x];
    }
    for (auto x : basket2) {
      --m[x];
    }
    vector<int> wraps;
    long long ans = 0, smallest = m.begin()->first;
    for (auto& [val, cnt] : m) {
      if (cnt & 1) return -1;
      fill_n(back_inserter(wraps), abs(cnt) / 2, val);
    }
    for (int i = 0; i < wraps.size() / 2; ++i) {
      ans += min(smallest * 2, (long long)wraps[i]);
    }
    return ans;
  }
};