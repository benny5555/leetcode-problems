#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maximumProduct(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto num : nums) {
      pq.push(num);
    }
    while (k--) {
      auto temp = pq.top();
      pq.pop();
      temp += 1;
      pq.push(temp);
    }
    long long ans = 1;
    int mod = 1e9 + 7;
    while (pq.size()) {
      ans *= pq.top();
      ans %= mod;
      pq.pop();
    }
    return ans % mod;
  }
};