#include <bits/stdc++.h>
using namespace std;
/*/我们可以考虑枚举数组中每个值n，并且以n作为子数组中的最小值，再乘以这个子数组的和，通过打擂台的方式得到最终答案。于是问题变成，

给定n，如何找到以n为最小值的子数组边界？

朴素的想法是维护左右指针不断扩大范围，但是这种做法总的时间复杂度是O(n^2)，会超时，我们需要寻找一种更快的方法。问题可以继续转化成，

对于数组中的每一个元素，分别找到左边、右边第一个比它小的元素的位置

单调栈刚好可以帮助我们在O(n)的时间内完成。维护两个单调递增栈分别找到左右下一个更小的元素位置。再结合前缀和，最后总的时间复杂度为O(n)
*/
class Solution {
 public:
  int maxSumMinProduct(vector<int>& nums) {
    long long ans = 0;
    constexpr int mod = 1e9 + 7;
    stack<int> stk;
    int n = nums.size();
    vector<long long> presum(n + 1);
    for (int i = 0; i < n; ++i) {
      presum[i + 1] = presum[i] + nums[i];
    }
    int j, k;
    for (int i = 0; i <= n; ++i) {
      while (stk.size() && (i == n || nums[stk.top()] > nums[i])) {
        j = stk.top(), stk.pop();
        k = stk.empty() ? 0 : stk.top() + 1;
        ans = max(ans, nums[j] * (presum[i] - presum[k]));
      }
      stk.push(i);
    }
    return ans % mod;
  }
};

int main() {
  vector<int> nums{1, 2, 3, 1, 5};
  Solution solution;
  solution.maxSumMinProduct(nums);
  return 0;
}