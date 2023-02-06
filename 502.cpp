#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int findMaximizedCapital(int k, int w, vector<int>& profits,
                           vector<int>& capital) {
    int n = capital.size(), i = 0;
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(),
         [&](int a, int b) { return capital[a] < capital[b]; });
    priority_queue<int> profit;
    while (k--) {
      while (i < n && w >= capital[ind[i]]) {
        profit.push(profits[ind[i++]]);
      }
      if (profit.size()) {
        w += profit.top();
        profit.pop();
      }
    }
    return w;
  }
};