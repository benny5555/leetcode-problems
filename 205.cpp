#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    vector<int> m1(256, -1), m2(256, -1);
    int n = s.size();
    for (int i = 0; s[i]; ++i) {
      if (m1[s[i]] != m2[t[i]]) return false;
      m1[s[i]] = m2[t[i]] = i;
    }
    return true;
  }
};