#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool canAttendMeetings(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
      if (a[0] == b[0]) return a[1] > b[1];
      return a[0] < b[0];
    });
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] < intervals[i - 1][1]) return false;
    }
    return true;
  }
};