#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int wordCount(vector<string>& startWords, vector<string>& targetWords) {
    int ans = 0;
    unordered_set<int> s;
    for (auto& word : startWords) {
      int mask = 0;
      for (auto c : word) {
        mask |= 1 << (c - 'a');
      }
      s.insert(mask);
    }
    for (auto& word : targetWords) {
      int mask = 0;
      for (auto c : word) {
        mask |= 1 << (c - 'a');
      }
      for (auto c : word) {
        if (s.count(mask ^ (1 << (c - 'a')))) {
          ++ans;
          break;
        }
      }
    }
    return ans;
  }
};