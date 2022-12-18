#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long wonderfulSubstrings(string word) {
    using ll = long long;
    unordered_map<int, int> m{{0, 1}};
    ll ans = 0;
    unordered_set<int> s;
    int state = 0;
    for (auto &w : word) {
      state ^= 1 << (w - 'a');
      s.insert(w);
      for (auto c : s) {
        ans += m[state ^ (1 << (c - 'a'))];
      }

      ans += m[state]++;
    }
    return ans;
  }
};