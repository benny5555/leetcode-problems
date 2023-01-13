#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long maxKelements(vector<int>& nums, int k) {
    using ll = long long;
    ll ans = 0;
    priority_queue<int> que;
    for (auto num : nums) {
      que.push(num);
    }
    while (k--) {
      auto now = que.top();
      que.pop();
      ans += now;
      que.push(ceil((double)now / 3));
    }
    return ans;
  }
};