#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    int ans = 0, i = 0;
    unordered_map<int, int> m;
    for (auto x : fruits) {
      ++m[x];
      if (m.size() <= 2) {
        int temp = 0;
        for (auto& [_, cnt] : m) {
          temp += cnt;
        }
        ans = max(ans, temp);
      }
      while (m.size() > 2) {
        --m[fruits[i]];
        if (m[fruits[i]] == 0) {
          m.erase(fruits[i]);
        }
        ++i;
      }
    }
    return ans;
  }
};