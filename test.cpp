#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> &A) {
  int n = A.size(), start_odd = 1, start_even = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0 && A[i] == A[start_even]) {
      ans = max(ans, i - min(start_even, start_odd) + 1);
    } else if (i % 2 == 1 && A[i] == A[start_odd]) {
      ans = max(ans, i - min(start_even, start_odd) + 1);
    } else if (i & 1) {
      start_odd = i;
    } else {
      start_even = i;
    }
  }
  return ans;
}

int main() {
  vector<vector<int>> v;
  v.push_back({3, 2, 3, 2, 3});
  v.push_back({7, 4, -2, 4, -2, -9});
  v.push_back({7, -5, -5, -5, 7, -1, 7});
  v.push_back({4});
  v.push_back({7, 3, 1});
  for (auto &temp : v) {
    cout << solution(temp) << endl;
  }
  return 0;
}