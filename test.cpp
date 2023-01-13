#include <bits/stdc++.h>
using namespace std;
class Solution {
  struct worker {
    int left_to_right, pick_old, right_to_left, put_new, ind, time;
    worker(int a, int b, int c, int d, int e, int f = 0)
        : left_to_right(a),
          pick_old(b),
          right_to_left(c),
          put_new(d),
          ind(e),
          time(f) {}
    bool operator<(const worker& b) const {
      if (left_to_right + right_to_left == b.left_to_right + b.right_to_left)
        return ind < b.ind;
      return left_to_right + right_to_left < b.left_to_right + b.right_to_left;
    }
  };

 public:
  int findCrossingTime(int n, int k, vector<vector<int>>& time) {
    priority_queue<worker, vector<worker>, less<>> left, right, to_put, picking;
    for (int i = 0; i < k; ++i) {
      left.push(worker(time[i][0], time[i][1], time[i][2], time[i][3], i));
    }
    int ans = 0;
    int now = 0;
    while (n) {
      while (right.size()) {
        auto temp = right.top();
        right.pop();
        now += temp.right_to_left;
        ans = now;
        picking.push(temp);
      }
      auto worker = left.top();
      left.pop();
    }
    return ans;
  }
};