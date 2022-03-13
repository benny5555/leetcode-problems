#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long minimalKSum(vector<int>& nums, int k) {
    long long ans = (long long)k * (k + 1) / 2, last = 0;
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    while (pq.size() && pq.top() <= k) {
      if (pq.top() != last) ans += (++k) - pq.top();
      last = pq.top();
      pq.pop();
    }
    return ans;
  }
};