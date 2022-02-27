#include <bits/stdc++.h>
using namespace std;
class MyStack {
 private:
  queue<int> que;

 public:
  MyStack() {}

  void push(int x) {
    int size = que.size();
    que.push(x);
    while (size--) {
      que.push(que.front());
      que.pop();
    }
  }

  int pop() {
    int ans = que.front();
    que.pop();
    return ans;
  }

  int top() { return que.front(); }

  bool empty() { return que.empty(); }
};