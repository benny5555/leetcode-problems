#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int similarPairs(vector<string> &words) {
    // unordered_map<int, int> m;
    // for (auto &w : words)
    //   ++m[accumulate(begin(w), end(w), 0,
    //                  [](int res, char ch) { return res | (1 << (ch - 'a'));
    //                  })];
    // return accumulate(begin(m), end(m), 0, [](int res, const auto &p) {
    //   printf("res =%d\n", res);
    //   return res + p.second * (p.second - 1) / 2;
    // });
    int ans = 0;
    vector<string> v;
    for (auto &w : words) {
      set<char> s(w.begin(), w.end());
      string temp;
      for (auto c : s) temp += c;
      v.push_back(temp);
    }
    for (int i = 0; i < v.size(); ++i) {
      for (int j = i + 1; j < v.size(); ++j) {
        if (v[i] == v[j]) ++ans;
      }
    }
    return ans;
  }
};