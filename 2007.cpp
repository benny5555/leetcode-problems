#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> findOriginalArray(vector<int>& changed) {
    vector<int> ans;
    map<int, int> m;
    for (int num : changed) {
      ++m[num];
    }
    while (m.size()) {
      auto iter = m.begin();
      if (iter->first == 0) {
        if (iter->second & 1) return {};
        fill_n(back_inserter(ans), iter->second / 2, 0);
        m.erase(0);
      } else {
        auto doubled = iter->first * 2;
        if (!m.count(doubled) || m[doubled] < iter->second) return {};
        fill_n(back_inserter(ans), iter->second, iter->first);
        m[doubled] -= iter->second;
        if (m[doubled] == 0) m.erase(doubled);
        m.erase(iter);
      }
    }
    return ans;
  }
};