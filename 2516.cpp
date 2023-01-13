#include <bits/stdc++.h>
using namespace std;
class Solution {
  unordered_set<char> cha{'a', 'b', 'c'};

 public:
  int takeCharacters(string s, int k) {
    unordered_map<char, int> exclude;
    exclude['a'] = exclude['b'] = exclude['c'] = -k;
    for (auto c : s) {
      ++exclude[c];
    }
    for (auto c : cha) {
      if (exclude[c] < 0) return -1;
    }
    unordered_map<char, int> cnt;
    for (auto c : s) cnt[c] = 0;
    int mid = INT_MIN;
    for (int i = 0, j = 0; s[j]; ++j) {
      ++cnt[s[j]];
      while (cnt[s[j]] > exclude[s[j]]) {
        --cnt[s[i++]];
      }
      if (j - i + 1 > mid) mid = j - i + 1;
    }
    return s.size() - mid;
  }
};