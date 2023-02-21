#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    vector<int> ans;
    int sum1 = 0, msum1 = 0, msum1ind = 0, sum2 = 0, msum12 = 0, msum12ind1 = 0,
        msum12ind2 = 0, sum3 = 0, mmax = 0;
    for (int i = 2 * k; i < nums.size(); ++i) {
      sum1 += nums[i - 2 * k];
      sum2 += nums[i - k];
      sum3 += nums[i];
      if (i >= 3 * k - 1) {
        if (sum1 > msum1) {
          msum1 = sum1;
          msum1ind = i - 3 * k + 1;
        }
        if (msum1 + sum2 > msum12) {
          msum12 = msum1 + sum2;
          msum12ind1 = msum1ind;
          msum12ind2 = i - 2 * k + 1;
        }
        if (msum12 + sum3 > mmax) {
          mmax = msum12 + sum3;
          ans = {msum12ind1, msum12ind2, i - k + 1};
        }
        sum1 -= nums[i - 3 * k + 1];
        sum2 -= nums[i - 2 * k + 1];
        sum3 -= nums[i - k + 1];
      }
    }
    return ans;
  }
};