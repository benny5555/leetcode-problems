#include <bits/stdc++.h>
using namespace std;
class Solution {
  bool isnumber(const string& s) {
    if (s.size()) {
      if (s[0] == '-' && s.size() >= 2) {
        return all_of(s.begin() + 1, s.end(), ::isdigit);
      }
      return all_of(s.begin(), s.end(), ::isdigit);
    }
    return false;
  }

 public:
  using ll = long long;
  stack<ll> s;
  int evalRPN(vector<string>& tokens) {
    for (auto& w : tokens) {
      if (isnumber(w)) {
        s.push(stoi(w));
      } else {
        ll b = s.top();
        s.pop();
        ll a = s.top();
        s.pop();
        if (w == "+") {
          s.push(a + b);
        } else if (w == "-") {
          s.push(a - b);
        } else if (w == "*") {
          s.push(a * b);
        } else if (w == "/") {
          s.push(a / b);
        }
      }
    }
    return s.top();
  }
};