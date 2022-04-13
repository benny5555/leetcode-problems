#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int largestInteger(int num) {
    string nums = to_string(num);
    priority_queue<int> odd, even;
    for (auto c : nums) {
      int digit = c - '0';
      if (digit & 1)
        odd.push(digit);
      else
        even.push(digit);
    }
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      ans *= 10;
      if ((nums[i] - '0') & 1) {
        ans += odd.top();
        odd.pop();
      } else {
        ans += even.top();
        even.pop();
      }
    }
    return ans;
  }
};