#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long makeSimilar(vector<int>& nums, vector<int>& target) {
    long long ans = 0;
    vector<vector<int>> num(2), t(2);
    for (int x : nums) {
      num[x % 2].push_back(x);
    }
    for (int x : target) {
      t[x % 2].push_back(x);
    }
    for (int i = 0; i < 2; ++i) {
      sort(num[i].begin(), num[i].end());
      sort(t[i].begin(), t[i].end());
    }
    for (int i = 0; i < num[0].size(); ++i) {
      ans += abs(num[0][i] - t[0][i]) / 2;
    }
    for (int i = 0; i < num[1].size(); ++i) {
      ans += abs(num[1][i] - t[1][i]) / 2;
    }
    return ans / 2;
  }
};