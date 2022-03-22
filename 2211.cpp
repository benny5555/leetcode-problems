#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int countCollisions(string directions) {
    int n = directions.size(), left = 0, right = n - 1;
    while (left < n && directions[left] == 'L') ++left;
    while (right > -1 && directions[right] == 'R') --right;
    int ans = 0;
    for (int i = left; i <= right; ++i) {
      if (directions[i] != 'S') ++ans;
    }
    return ans;
  }
};