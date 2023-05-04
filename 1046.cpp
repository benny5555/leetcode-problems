#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;
    for (auto x : stones) {
      pq.push(x);
    }
    while (pq.size() > 1) {
      auto largest = pq.top();
      pq.pop();
      auto second_largest = pq.top();
      pq.pop();
      pq.push(largest - second_largest);
    }
    return pq.size() ? pq.top() : 0;
  }
};