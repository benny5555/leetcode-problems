#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long subArrayRanges(vector<int>& nums) {
    long long ans = 0, n = nums.size(), j, k;
    stack<int> stk;
    for (int i = 0; i <= n; ++i) {
      while (stk.size() && nums[stk.top()] > (i == n ? INT_MIN : nums[i])) {
        j = stk.top(), stk.pop();
        k = stk.empty() ? -1 : stk.top();
        ans -= (long long)nums[j] * (i - j) * (j - k);
      }
      stk.push(i);
    }
    stk = stack<int>();
    for (int i = 0; i <= n; ++i) {
      while (stk.size() && nums[stk.top()] < (i == n ? INT_MAX : nums[i])) {
        j = stk.top(), stk.pop();
        k = stk.empty() ? -1 : stk.top();
        ans += (long long)nums[j] * (i - j) * (j - k);
      }
      stk.push(i);
    }
    return ans;
  }
};

int main() {
  vector<int> nums{1, 3, 3};
  Solution solution;
  solution.subArrayRanges(nums);
  return 0;
}