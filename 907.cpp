#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    long long ans = 0, mod = 1e9 + 7;
    int n = arr.size();
    // left[i]: when assuming i is the right end, the continuous bigger number
    // left to i;
    // right[i]: when assuming i the left end, the continuous bigger nunmber
    // right to i;
    vector<long long> left(n), right(n);
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
      while (stk.size() && arr[stk.top()] > arr[i]) stk.pop();
      left[i] = stk.empty() ? i : i - stk.top() - 1;
      stk.push(i);
    }
    while (stk.size()) stk.pop();
    for (int i = n - 1; i >= 0; --i) {
      while (stk.size() && arr[stk.top()] >= arr[i]) stk.pop();
      right[i] = stk.empty() ? n - 1 - i : stk.top() - 1 - i;
      stk.push(i);
    }
    for (int i = 0; i < n; ++i) {
      // arr[i] is the one of the ends.
      ans += (left[i] + right[i] + 1) * arr[i];
      // arr[i] is not one of the ends.
      ans += left[i] * right[i] * arr[i];
    }
    return ans % mod;
  }
};