#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (int x : nums) {
      ++m[x];
    }
    vector<pair<int, int>> temp;
    for (auto& [x, cnt] : m) {
      temp.push_back(make_pair(cnt, x));
    }
    sort(temp.rbegin(), temp.rend());
    vector<int> ans;
    for (int i = 0; i < k; ++i) {
      ans.push_back(temp[i].second);
    }
    return ans;
  }
};