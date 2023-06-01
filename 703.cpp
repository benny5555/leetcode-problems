#include <bits/stdc++.h>
using namespace std;
class KthLargest {
  int k;
  priority_queue<int, vector<int>, greater<int>> pq;

 public:
  KthLargest(int _k, vector<int>& nums) : k(_k) {
    for (int x : nums) {
      pq.push(x);
      if (pq.size() > k) {
        pq.pop();
      }
    }
  }

  int add(int val) {
    pq.push(val);
    if (pq.size() > k) {
      pq.pop();
    }
    return pq.top();
  }
};