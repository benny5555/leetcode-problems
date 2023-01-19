#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
#define v vector
    v<v<int>> ans;
    int n = intervals.size(), i = 0;
    while (i < n && intervals[i][1] < newInterval[0]) {
      ans.push_back(intervals[i++]);
    }
    for (; i < n && newInterval[1] >= intervals[i][0]; ++i) {
      if (intervals[i][0] < newInterval[0]) newInterval[0] = intervals[i][0];
      if (intervals[i][1] > newInterval[1]) newInterval[1] = intervals[i][1];
    }
    ans.push_back(newInterval);
    ans.insert(ans.end(), intervals.begin() + i, intervals.end());
    return ans;
  }
};