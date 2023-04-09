#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                              long long success) {
    sort(potions.begin(), potions.end());
    int n = spells.size();
    vector<int> ans;
    for (int x : spells) {
      long need = (success + x - 1) / x;
      ans.push_back(potions.end() -
                    lower_bound(potions.begin(), potions.end(), need));
    }
    return ans;
  }
};