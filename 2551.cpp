#include <bits/stdc++.h>
using namespace std;
/*
First for any of distributions,
we will sum up A[0] and A[n - 1] in the total socre,
so this won't make any difference between max and min.

To split into k bags,
we actually choose k-1 cut points:
A[0]...A[i1]
A[i1+1]....A[i2]
A[i2+1]....A[i3]
....
A[ik+1]....A[n-1]

The result score is:
(A[0] + A[i1]) + (A[i1 + 1] + A[i2]) +..... + (A[ik+1] + A[n-1])
equals to
A[0] + (A[i1] + A[i1+1]) + (A[i2] + A[i2+1]) + (A[ik] + A[ik+1]) + A[n-1]....

So the problem turns out to be,
calculate the max/min sum of k - 1 numbers in
A[0] + A[1], A[1] + A[2],..., A[n-1] + A[n].

We can simply sort them in O(sort)
or we can apply a priority queue in O(nlogk).
*/
class Solution {
 public:
  long long putMarbles(vector<int>& weights, int k) {
    using ll = long long;
    ll ans = 0, n = weights.size() - 1;
    for (int i = 0; i < n; ++i) {
      weights[i] += weights[i + 1];
    }
    weights.pop_back();
    sort(weights.begin(), weights.end());
    for (int i = 0; i < k - 1; ++i) {
      ans += weights[n - 1 - i] - weights[i];
    }
    return ans;
  }
};