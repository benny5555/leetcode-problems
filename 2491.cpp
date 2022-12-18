#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long dividePlayers(vector<int>& skill) {
    long long ans = 0;
    sort(skill.begin(), skill.end());
    int score = skill[0] + skill[skill.size() - 1];
    for (int i = 0, j = skill.size() - 1; i < j; ++i, --j) {
      if (skill[i] + skill[j] != score) return -1;
      ans += skill[i] * skill[j];
    }
    return ans;
  }
};