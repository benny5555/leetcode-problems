#include <bits/stdc++.h>
using namespace std;
// class Solution {
//  public:
//   bool containsNearbyDuplicate(vector<int>& nums, int k) {
//     unordered_map<int, vector<int>> m;
//     int n = nums.size();
//     for (int i = 0; i < n; ++i) {
//       m[nums[i]].push_back(i);
//     }
//     for (auto iter : m) {
//       for (int i = 1; i < iter.second.size(); ++i) {
//         if (iter.second[i] - iter.second[i - 1]) <= k) return true;
//       }
//     }
//     return false;
//   }
// };
class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> s;

    if (k <= 0) return false;
    if (k >= nums.size()) k = nums.size() - 1;

    for (int i = 0; i < nums.size(); i++) {
      if (i > k) s.erase(nums[i - k - 1]);
      if (s.find(nums[i]) != s.end()) return true;
      s.insert(nums[i]);
    }

    return false;
  }
};