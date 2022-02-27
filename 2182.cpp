#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  string repeatLimitedString(string s, int limit) {
    string ans;
    map<char, int, greater<char>> mmap;
    for (auto c : s) ++mmap[c];
    while (mmap.size()) {
      int left = mmap.begin()->second, cnt = 0;
      char c = mmap.begin()->first;
      mmap.erase(mmap.begin());
      while (left) {
        ++cnt;
        if (cnt > limit) {
          if (mmap.empty()) return ans;
          ans.push_back(mmap.begin()->first);
          --mmap.begin()->second;
          if (mmap.begin()->second == 0) mmap.erase(mmap.begin());
          cnt = 1;
        }
        ans.push_back(c);
        --left;
      }
    }
    return ans;
  }
};