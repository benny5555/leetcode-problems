#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long maximumBeauty(vector<int>& flowers, long long newFlowers,
                          long long target, long long full, long long partial) {
    sort(flowers.begin(), flowers.end(), [&](int& a, int& b) {
      if (a > target) a = target;
      if (b > target) b = target;
      return a < b;
    });
    if (flowers[0] == target) return flowers.size() * full;
    if (newFlowers >= target * flowers.size() -
                          accumulate(flowers.begin(), flowers.end(), 0ll)) {
      return max(full * flowers.size(),
                 full * (flowers.size() - 1) + partial * (target - 1));
    }
    vector<long long> presum(flowers.size());
    for (int i = 1; i < flowers.size(); ++i) {
      presum[i] = presum[i - 1] + i * (flowers[i] - flowers[i - 1]);
    }
    int n = flowers.size() - 1;
    while (flowers[n] == target) --n;
    unsigned long long ans = 0;
    while (newFlowers >= 0) {
      int max_ind =
          min(n, (int)(upper_bound(presum.begin(), presum.end(), newFlowers) -
                       presum.begin()) -
                     1);
      long long mmin =
          flowers[max_ind] + (newFlowers - presum[max_ind]) / (max_ind + 1);
      ans = max(ans, mmin * partial + full * (flowers.size() - n - 1));
      newFlowers -= target - flowers[n];
      --n;
    }
    return ans;
  }
};