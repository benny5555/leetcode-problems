#include <bits/stdc++.h>
using namespace std;

void op_quick_sort(int l, int r, vector<int>& arr) {
  srand(time(0));
  __op_quick_sort(l, r - 1, arr);
}
void __op_quick_sort(int l, int r, vector<int>& arr) {
  if (l >= r) return;
  int cut = re_partition(l, r, rand() % (r - l + 1) + l, arr);
  __op_quick_sort(l, cut - 1, arr);
  __op_quick_sort(cut + 1, r, arr);
}
int re_partition(int l, int r, int pivot, vector<int>& arr) {
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