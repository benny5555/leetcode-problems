#include <bits/stdc++.h>
using namespace std;
class BrowserHistory {
  vector<string> v;
  int cur, mmax;

 public:
  BrowserHistory(string homepage) : cur(0), mmax(0) { v.push_back(homepage); }

  void visit(string url) {
    ++cur;
    if (cur >= v.size()) {
      v.push_back(url);
    } else {
      v[cur] = url;
    }
    mmax = cur;
  }

  string back(int steps) {
    cur = max(0, cur - steps);
    return v[cur];
  }

  string forward(int steps) {
    cur = min(mmax, cur + steps);
    return v[cur];
  }
};