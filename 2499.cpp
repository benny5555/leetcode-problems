#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    long long ans = 0;
    unordered_map<int, int> m;
    int maxFreq = 0, maxFreqVal = 0, toSwap = 0;
    for (int i = 0; i < n; ++i) {
      if (nums1[i] == nums2[i]) {
        ++m[nums1[i]];
        if (m[nums1[i]] > maxFreq) {
          maxFreqVal = nums1[i];
          maxFreq = m[nums1[i]];
        }
        ++toSwap;
        ans += i;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (maxFreq > toSwap / 2 && nums1[i] != nums2[i] &&
          nums1[i] != maxFreqVal && nums2[i] != maxFreqVal) {
        ans += i;
        ++toSwap;
      }
    }
    if (maxFreq > toSwap / 2) return -1;
    return ans;
  }
};