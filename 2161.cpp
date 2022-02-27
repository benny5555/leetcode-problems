#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> left, right, mid;
    for (int num : nums) {
      if (num < pivot) {
        left.push_back(num);
      } else if (num > pivot) {
        right.push_back(num);
      } else {
        mid.push_back(num);
      }
    }
    mid.insert(mid.end(), right.begin(), right.end());
    left.insert(left.end(), mid.begin(), mid.end());
    return left;
  }
};