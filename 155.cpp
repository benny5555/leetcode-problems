#include <bits/stdc++.h>
using namespace std;
class MinStack {
 private:
  stack<int> stk, mmin;

 public:
  MinStack() {}

  void push(int val) {
    stk.push(val);
    if (mmin.empty() || val < mmin.top())
      mmin.push(val);
    else
      mmin.push(mmin.top());
  }

  void pop() {
    stk.pop();
    mmin.pop();
  }

  int top() { return stk.top(); }

  int getMin() { return mmin.top(); }
};