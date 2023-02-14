#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    long long ans = 0, sum = 0, n = nums1.size();
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; ++i) {
      arr.push_back(make_pair(nums2[i], nums1[i]));
    }
    sort(arr.rbegin(), arr.rend());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& [m, s] : arr) {
      sum += s;
      pq.push(s);
      if (pq.size() > k) {
        sum -= pq.top();
        pq.pop();
      }
      if (pq.size() == k) {
        ans = max(ans, sum * m);
      }
    }
    return ans;
  }
};