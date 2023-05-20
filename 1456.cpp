#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxVowels(string s, int k) {
    unordered_set<char> mset{'a', 'e', 'i', 'o', 'u'};
    int ans = 0, temp = 0;
    for (int i = 0; i < k; ++i) {
      temp += mset.count(s[i]);
      ans = max(ans, temp);
    }
    for (int i = k; i < s.size(); ++i) {
      temp -= mset.count(s[i - k]);
      temp += mset.count(s[i]);
      ans = max(ans, temp);
    }
    return ans;
  }
};