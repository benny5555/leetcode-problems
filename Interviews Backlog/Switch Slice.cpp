/*
We call an array switching if all numbers in even positions are equal and all
numbers in odd positions areequal.For example: [3, -7,3, -7, 3] and [4, 4, 4]
are switching, but [5, 5, 4, 5, 4] and [-3, 2, 3] are not switching.What is the
length of the longest switching slice (continuous fragment) in a given array
A?Write a function: int solution(vector<int> &A); that, given an array A
consisting of N integers, returns the length of the longest switching slice in
AExamples:
1. Given A = [3, 2, 3, 2, 3l, the function should return 5, because the whole
array is switching2. Given A = [7, 4, -2, 4, -2, -9, the function should
return 4. The longest switching slice is (4, -2, 4, -2.
3. Given A = (7, -5, -5, -5, 7, -1, 7), the function should return 3. There are
two switching slices of equal length:[-5,-5,-5] and7,-1,7].
4. Given A = (4), the function should return 1. A single-element slice is also a
switching sliceWrite an efficient algorithm for the following assumptions N is
an integer within the range [1..100,000];each element of array A is an integer
within the range [-1,000,000,000..1,000,000,000]
*/
#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> &A) {
  int n = A.size();
  if (n <= 2) return n;
  int start_odd = 1, start_even = 0;
  int ans = 1;
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