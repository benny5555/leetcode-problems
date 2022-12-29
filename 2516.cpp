#include <bits/stdc++.h>
using namespace std;
class Solution {
  char characters[3] = {'a', 'b', 'c'};

 public:
  int takeCharacters(string s, int k) {
    int exclude[256]{}, cnt[256]{};
    for (auto c : s) {
      ++exclude[c];
    }
    for (auto c : characters) {
      exclude[c] -= k;
      if (exclude[c] < 0) return -1;
    }
    int middle = 0;
    for (int left = 0, right = 0; right < s.size(); ++right) {
      ++cnt[s[right]];
      while (cnt[s[right]] > exclude[s[right]]) {
        --cnt[s[left++]];
      }
      middle = max(middle, right - left + 1);
    }
    return s.size() - middle;
  }
};