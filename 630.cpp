#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), [&](const auto& a, const auto& b) {
      if (a[1] == b[1]) return a[0] < b[0];
      return a[1] < b[1];
    });
    int curtime = 0;
    priority_queue<int> pq;
    for (auto& course : courses) {
      curtime += course[0];
      pq.push(course[0]);
      if (curtime > course[1]) {
        curtime -= pq.top();
        pq.pop();
      }
    }
    return pq.size();
  }
};