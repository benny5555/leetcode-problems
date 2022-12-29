#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int closetTarget(vector<string>& words, string target, int startIndex) {
    int ans = INT_MAX, n = words.size();
    for (int i = 0; i < n; ++i) {
      if (words[i] == target) {
        int temp = abs(startIndex - i);
        ans = min({ans, temp, n - temp});
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};