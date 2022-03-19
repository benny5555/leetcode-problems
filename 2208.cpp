#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int halveArray(vector<int>& nums) {
    double sum = accumulate(nums.begin(), nums.end(), 0ll);
    priority_queue<double> pq(nums.begin(), nums.end());
    int ans = 0;
    double half = sum / 2;
    while (pq.size()) {
      auto temp = pq.top();
      pq.pop();
      temp /= 2;
      ++ans;
      sum -= temp;
      if (sum <= half) break;
      pq.push(temp);
    }
    return ans;
  }
};