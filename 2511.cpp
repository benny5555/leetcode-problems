#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int captureForts(vector<int>& forts) {
    int ans = 0;
    bool start = false;
    int last = 0;
    for (int i = 0; i < forts.size(); ++i) {
      if (forts[i]) {
        if (forts[i] == -forts[last]) {
          ans = max(ans, i - last - 1);
        }
        last = i;
      }
    }
    return ans;
  }
};