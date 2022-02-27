#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    unordered_map<int, int> m1, m2;
    int n = nums.size();
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i += 2) {
      m1[nums[i]]++;
      ++cnt1;
    }
    for (int i = 1; i < n; i += 2) {
      m2[nums[i]]++;
      ++cnt2;
    }
    int pivot1 = 0, pivot11 = 0, pivot2 = 0, pivot22 = 0, num1 = 0, num2 = 0;
    for (auto iter : m1) {
      if (iter.second > pivot1) {
        pivot11 = pivot1;
        pivot1 = iter.second;
        num1 = iter.first;
      } else if (iter.second > pivot11) {
        pivot11 = iter.second;
      }
    }
    for (auto iter : m2) {
      if (iter.second > pivot2) {
        pivot22 = pivot2;
        pivot2 = iter.second;
        num2 = iter.first;
      } else if (iter.second > pivot22) {
        pivot22 = iter.second;
      }
    }
    if (num1 != num2) {
      return cnt1 - pivot1 + cnt2 - pivot2;
    } else {
      if (pivot11 > pivot22)
        pivot1 = pivot11;
      else
        pivot2 = pivot22;
      return cnt1 - pivot1 + cnt2 - pivot2;
    }
  }
};