#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string simplifyPath(string path) {
    deque<string> que;
    int n = path.size(), i = 0;
    while (i < n) {
      if (i < n && path[i] == '/')
        ++i;
      else {
        string temp;
        while (i < n && path[i] != '/') temp += path[i++];
        if (temp == ".." && que.size()) {
          que.pop_back();
        } else if (temp != ".." && temp != ".") {
          que.push_back(temp);
        }
      }
    }
    string ans = "/";
    while (que.size()) {
      ans += que.front() + "/";
      que.pop_front();
    }
    if (ans.size() > 1) ans.pop_back();
    return ans;
  }
};