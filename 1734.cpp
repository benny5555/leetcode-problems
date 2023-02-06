#include <bits/stdc++.h>
using namespace std;
/*
We make good use of the condition "n is odd" as follow
a1,(a2,a3),(a4,a5).....,
making the decoded into pairs.
a2^a3 = A[1]
a4^a5 = A[3]
a6^a7 = A[5]
...
so we can have the result of a2^a3^a4...^an.
And a1,a2,a3... is a permuatation of 1,2,3,4..n

so we can have
a1 = 1^2^3...^n^a2^a2^a3...^an

Then we can deduct the whole decoded array.

*/
class Solution {
 public:
  vector<int> decode(vector<int>& encoded) {
    int n = encoded.size() + 1;
    vector<int> ans;
    int first = 0;
    for (int i = 0; i <= n; ++i) {
      first ^= i;
      if (i < n && (i & 1)) {
        first ^= encoded[i];
      }
    }
    ans.push_back(first);
    for (int x : encoded) {
      ans.push_back(ans.back() ^ x);
    }
    return ans;
  }
};