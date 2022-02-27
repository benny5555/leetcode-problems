#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
    int n = fruits.size();
    vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + fruits[i][1];
    int ans = 0;
    auto cmp = [](auto &a, int b) { return a[0] < b; };
    auto cmp2 = [](int b, auto &a) { return b < a[0]; };
    for (int one = k; one >= 0; --one) {
      int two = (k - one) / 2;
      int l = startPos - one, r = startPos + two;
      auto left = lower_bound(fruits.begin(), fruits.end(), l, cmp) -
                  fruits.begin(),
           right = upper_bound(fruits.begin(), fruits.end(), r, cmp2) -
                   fruits.begin();
      ans = max(ans, sum[right] - sum[left]);

      l = startPos - two, r = startPos + one;
      left = lower_bound(fruits.begin(), fruits.end(), l, cmp) - fruits.begin();
      right =
          upper_bound(fruits.begin(), fruits.end(), r, cmp2) - fruits.begin();
      ans = max(ans, sum[right] - sum[left]);
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> fruits = {{2, 8}, {6, 3}, {8, 6}};
  int startPos = 5, k = 4;
  Solution solution;
  solution.maxTotalFruits(fruits, startPos, k);
  return 0;
}