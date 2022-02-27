#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<int, int> m1, m2;
    for (int i = 0; s[i]; ++i) {
      ++m1[s[i]], ++m2[t[i]];
    }
    for (auto iter : m1) {
      if (iter.second != m2[iter.first]) return false;
    }
    return true;
  }
};