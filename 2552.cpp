#include <bits/stdc++.h>
using namespace std;
/*
First precompute an array lessthan where lessthan[i][j] is the number of
elements less than i in the first j elements.

Then you loop through pairs (j, k), so for each iteration, you only need to find
how many possible pairs (i, l) there are.

To do this, notice the number of potential i is equal to the count of numbers
less than nums[k] before j. And the number of potential l is equal to the count
of numbers greater than nums[j] after k. We can compute this in O(1) using
lessthan. See below.
*/
class Solution {
 public:
  long long countQuadruplets(vector<int>& nums) {
    using ll = long long;
    ll ans = 0, n = nums.size();
#define v vector
    v<v<int>> lessthan(n + 1, v<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        lessthan[j][i] = lessthan[j][i - 1] + (nums[i - 1] < j);
      }
    }
    for (int j = 0; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (nums[j] > nums[k]) {
          ll l = n - nums[j] - (k - lessthan[nums[j]][k + 1]);
          ll i = lessthan[nums[k]][j + 1];
          ans += i * l;
        }
      }
    }
    return ans;
  }
};