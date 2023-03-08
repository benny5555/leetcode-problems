#include <bits/stdc++.h>
using namespace std;
int partition(int l, int r, int pivot, vector<int>& arr) {
  swap(arr[pivot], arr[r]);
  int left = l, right = r;
  while (left < right) {
    while (left < right && arr[left] <= arr[r]) ++left;
    while (left < right && arr[right] >= arr[r]) --right;
    swap(arr[left], arr[right]);
  }
  swap(arr[left], arr[r]);
  return left;
}
void _quick_sort(int l, int r, vector<int>& arr) {
  if (l >= r) return;
  int pivot = partition(l, r, rand() % (r - l + 1) + l, arr);
  _quick_sort(l, pivot - 1, arr);
  _quick_sort(pivot + 1, r, arr);
}
void quick_sort(int l, int r, vector<int>& arr) {
  srand(time(0));
  return _quick_sort(l, r - 1, arr);
}

class Solution {
  void mysort(vector<int>& nums) { sort(nums.begin(), nums.end()); }

 public:
  vector<int> sortArray(vector<int>& nums) {
    mysort(nums);
    return nums;
  }
};