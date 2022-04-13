#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long numberOfWays(string s) {
    long long ans = 0, cnt1 = 0, cnt0 = 0;
    for (auto c : s) {
      if (c == '0')
        ++cnt0;
      else
        ++cnt1;
    }
    long long count1 = 0, count0 = 0;
    for (auto c : s) {
      if (c == '0') {
        ans += count1 * cnt1;
        --cnt0;
        ++count0;
      } else {
        ans += count0 * cnt0;
        --cnt1;
        ++count1;
      }
    }
    return ans;
  }
};