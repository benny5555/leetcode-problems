#include <bits/stdc++.h>
using namespace std;
struct FenWick {
  int n;
  vector<int> arr;
  FenWick(int limit) : n(limit), arr(n + 1) {}
  void update(int i, int delta) {
    for (; i <= n; i += i & -i) {
      arr[i] += delta;
    }
  }
  int query(int i) {
    int ans = 0;
    for (; i > 0; i -= i & -i) {
      ans += arr[i];
    }
    return ans;
  }
};
class Solution {
 public:
  int createSortedArray(vector<int>& instructions) {
    int ans = 0, n = instructions.size(), mod = 1e9 + 7;
    FenWick fw(100000);
    for (int i = 0; i < n; ++i) {
      ans = (ans + min(fw.query(instructions[i] - 1),
                       i - fw.query(instructions[i]))) %
            mod;
      fw.update(instructions[i], 1);
    }
    return ans;
  }
};