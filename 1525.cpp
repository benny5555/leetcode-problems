#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int numSplits(string s) {
    int ans = 0, n = s.size();
    unordered_set<char> mset;
    vector<int> right(n);
    for (int i = n - 1; i >= 0; --i) {
      mset.insert(s[i]);
      right[i] = mset.size();
    }
    mset.clear();
    for (int i = 0; i < n - 1; ++i) {
      mset.insert(s[i]);
      if (mset.size() == right[i + 1]) {
        ++ans;
      }
    }
    return ans;
  }
};