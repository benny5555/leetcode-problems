#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<vector<int>> findDifference(vector<int>& arr1, vector<int>& arr2) {
    vector<int> ans1, ans2;
    unordered_set<int> s1(arr1.begin(), arr1.end()),
        s2(arr2.begin(), arr2.end());
    for (auto x : s1) {
      if (!s2.count(x)) {
        ans1.push_back(x);
      }
    }
    for (auto x : s2) {
      if (!s1.count(x)) {
        ans2.push_back(x);
      }
    }
    return {ans1, ans2};
  }
};