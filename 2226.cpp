#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  long long func(vector<int>& arr, int mid) {
    long long ans = 0;
    for (int num : arr) {
      ans += num / mid;
    }
    return ans;
  }

 public:
  int maximumCandies(vector<int>& candies, long long k) {
    int l = 0, r = *max_element(candies.begin(), candies.end());
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (func(candies, mid) < k)
        r = mid - 1;
      else
        l = mid;
    }
    return l;
  }
};