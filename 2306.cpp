#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long distinctNames(vector<string>& ideas) {
    using ll = long long;
    ll ans = 0;
    unordered_set<string> cnt[26];
    for (auto& s : ideas) {
      cnt[s[0] - 'a'].insert(s.substr(1));
    }
    for (int i = 0; i < 26; ++i) {
      for (int j = i + 1; j < 26; ++j) {
        ll c1 = 0, c2 = 0;
        for (auto& s : cnt[i]) {
          if (!cnt[j].count(s)) ++c1;
        }
        for (auto& s : cnt[j]) {
          if (!cnt[i].count(s)) ++c2;
        }
        ans += c1 * c2;
      }
    }
    return ans * 2;
  }
};