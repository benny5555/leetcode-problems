#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimumPartition(string s, int k) {
    if (k < 10) {
      for (auto c : s) {
        if ((c - '0') > k) {
          return -1;
        }
      }
    }
    int n = to_string(k).size();
    int i = 0, ans = 0;
    while (i < s.size()) {
      if (stoi(s.substr(i, n)) > k) {
        i += n - 1;
      } else {
        i += n;
      }
      ++ans;
    }
    return ans;
  }
};