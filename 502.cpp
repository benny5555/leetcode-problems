#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int findMaximizedCapital(int k, int w, vector<int>& profits,
                           vector<int>& capital) {
    int n = profits.size(), i = 0;
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(),
         [&](int a, int b) { return capital[a] < capital[b]; });
    priority_queue<int> pq;

    while (k--) {
      while (i < n && capital[ind[i]] <= w) {
        pq.push(profits[ind[i++]]);
      }
      if (pq.size()) {
        w += pq.top();
        pq.pop();
      }
    }
    return w;
  }
};