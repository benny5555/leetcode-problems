#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<long long> getDistances(vector<int>& arr) {
    int n = arr.size();
    vector<long long> ans(n), left(n), right(n), presum(n);
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; ++i) {
      m[arr[i]].push_back(i);
    }
    for (auto iter : m) {
      auto& v = iter.second;
      for (int i = 1; i < v.size(); ++i) {
        left[v[i]] = left[v[i - 1]] + i * (long long)(v[i] - v[i - 1]);
      }
    }
    for (auto iter : m) {
      auto& v = iter.second;
      for (int i = v.size() - 2; i >= 0; --i) {
        right[v[i]] =
            right[v[i + 1]] + (v.size() - i - 1) * (long long)(v[i + 1] - v[i]);
      }
    }
    for (int i = 0; i < n; ++i) {
      ans[i] = left[i] + right[i];
    }
    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> v{2, 1, 3, 1, 2, 3, 3};

  solution.getDistances(v);
  return 0;
}