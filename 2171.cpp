#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long minimumRemoval(vector<int>& arr) {
    long long ans = LLONG_MAX;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<long long> sum(n + 1);
    for (int i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + arr[i];
    }
    for (int i = 0; i < n; ++i) {
      ans = min(ans, sum[n] - ((long long)arr[i] * (n - i)));
    }
    return ans;
  }
};