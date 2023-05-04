#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string predictPartyVictory(string senate) {
    queue<int> que1, que2;
    int n = senate.size();
    for (int i = 0; i < n; ++i) {
      if (senate[i] == 'R') {
        que1.push(i);
      } else {
        que2.push(i);
      }
    }
    while (que1.size() && que2.size()) {
      auto ri = que1.front(), di = que2.front();
      que1.pop(), que2.pop();
      if (ri < di) {
        que1.push(ri + n);
      } else {
        que2.push(di + n);
      }
    }
    return que1.size() > que2.size() ? "Radiant" : "Dire";
  }
};