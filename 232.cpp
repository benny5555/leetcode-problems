#include <bits/stdc++.h>
using namespace std;
class MyQueue {
  stack<int> stk1, stk2;

 public:
  MyQueue() {}

  void push(int x) { stk1.push(x); }

  int pop() {
    if (stk2.empty()) {
      while (stk1.size()) {
        stk2.push(stk1.top());
        stk1.pop();
      }
    }
    auto ans = stk2.top();
    stk2.pop();
    return ans;
  }

  int peek() {
    if (stk2.empty()) {
      while (stk1.size()) {
        stk2.push(stk1.top());
        stk1.pop();
      }
    }
    return stk2.top();
  }

  bool empty() { return stk1.empty() && stk2.empty(); }
};