#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> ans;
    int pre = 0;
    transform(arr.begin(), arr.end(), arr.begin(), [&](int x) {
      pre ^= x;
      return pre;
    });
    for (auto& q : queries) {
      int left = q[0], right = q[1];
      ans.push_back(arr[right] ^ (left == 0 ? 0 : arr[left - 1]));
    }
    return ans;
  }
};