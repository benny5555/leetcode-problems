#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  int func(vector<int>& arr) {
    vector<int> ans;
    for (int num : arr) {
      if (ans.empty() || ans.back() <= num)
        ans.push_back(num);
      else
        *upper_bound(ans.begin(), ans.end(), num) = num;
    }
    return ans.size();
  }

 public:
  int kIncreasing(vector<int>& arr, int k) {
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < k; ++i) {
      vector<int> temp;
      for (int j = i; j < n; j += k) temp.push_back(arr[j]);
      ans += func(temp);
    }
    return arr.size() - ans;
  }
};