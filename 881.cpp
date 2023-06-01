#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int l = 0, n = people.size(), r = n - 1, ans = 0;
    while (l <= r) {
      int sum = people[l] + people[r];
      if (sum <= limit) {
        ++ans, ++l, --r;
      } else {
        ++ans, --r;
      }
    }
    return ans;
  }
};