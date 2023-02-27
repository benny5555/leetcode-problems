#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimumDeviation(vector<int>& nums) {
    priority_queue<int> pq;
    int ans = INT_MAX, mmin = INT_MAX;
    for (auto n : nums) {
      n = n % 2 ? 2 * n : n;
      pq.push(n);
      mmin = min(mmin, n);
    }
    while (pq.top() % 2 == 0) {
      auto temp = pq.top();
      pq.pop();
      ans = min(ans, temp - mmin);
      mmin = min(mmin, temp / 2);
      pq.push(temp / 2);
    }
    return min(ans, pq.top() - mmin);
  }
};