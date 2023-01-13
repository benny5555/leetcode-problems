#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maximumCount(vector<int>& nums) {
    int pos = upper_bound(nums.begin(), nums.end(), 0) - nums.begin(),
        neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin(),
        n = nums.size();
    return max(neg, n - pos);
  }
};