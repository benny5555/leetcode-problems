#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    vector<pair<double, double>> workers;
    int n = quality.size();
    for (int i = 0; i < n; ++i) {
      workers.push_back(
          make_pair((double)(wage[i]) / quality[i], (double)quality[i]));
    }
    sort(workers.begin(), workers.end());
    double ans = DBL_MAX, tempq = 0;
    priority_queue<int> pq;
    for (auto& [ratio, q] : workers) {
      tempq += q;
      pq.push(q);
      if (pq.size() > k) {
        tempq -= pq.top();
        pq.pop();
      }
      if (pq.size() == k) {
        ans = min(ans, tempq * ratio);
      }
    }
    return ans;
  }
};