#include <Bits/stdc++.h>
using namespace std;
struct SegmentTree {
  int n;
  // left to store index of rightend of contiguous characters of segment l to h
  // from left side.
  // right to store index of contiguous characters of segment l to h from right
  //  side
  vector<int> nums, left, right;
  vector<char> lc, rc;
  SegmentTree(string& s)
      : n(s.size()),
        nums(4 * n + 5),
        left(4 * n + 5, -1),
        right(4 * n + 5, -1),
        lc(4 * n + 5, '*'),
        rc(4 * n + 5, '*') {
    build(0, s, 0, n - 1);
  }
  void build(int in, string& s, int l, int r) {
    if (l > r) return;
    if (l == r) {
      lc[in] = rc[in] = s[l];
      left[in] = right[in] = l;
      nums[in] = 1;
      return;
    }
    int mid = (l + r) / 2;
    build(2 * in + 1, s, l, mid);
    build(2 * in + 2, s, mid + 1, r);
    merge(in, l, mid, r);
  }
  void merge(int in, int l, int mid, int r) {
    /* Assuming we have done calculation for both left and right child of a
segment, calculation for parent is as follows: for example, parent = "smmh",
then the leftchild = "sm", rightchild = "mh", the index of segment from l to h
is in and left child segment is from l to m and right child segment is from m+1
to h , where m = (l+h)/2

  leftmost character of segment is the leftmost character of left child.

  rightmost character of segment is the rightmost character of right child.

  Atfirst, left[in] = left[left_child] and right[in] = right[left_child], where

  leftchild and rightchild are the index of segment of left and right child

  suppose, if rightmost char of left child == leftmost char of right child and
also left[left_child] == m (end of segment of left child), then new left[in] =
left[right_child]. similarly, if right[right_child] == m+1 (start of the
segement of right child), the new value right[in] = right[left_child]

  Now,  longest substring can be, from l to left[in], or from right[in] to h, or
from right[left_child] to left[right_child] if rightmost char of left child ==
leftmost char of right child. Or it can be max of longest substring of leftchild
and rightchild.
for a string s = "abssefgth", we have segement froml = 2 toh = 8 ( ssefgth ).
Then the five parameter are:

longest substring in segment is 2
leftmost character of segment is s
rightmost character of segment is h
index of rightend of contiguous characters of segment is 3 ( "ss" => 2 to 3)
index of rightend of contiguous characters of segment is 8 ( "h" => 8 to 8)
*/
    int lnode = in * 2 + 1, rnode = in * 2 + 2, mmax = 0;
    lc[in] = lc[lnode];
    rc[in] = rc[rnode];
    left[in] = left[lnode];
    right[in] = right[rnode];
    if (rc[lnode] == lc[rnode]) {
      if (left[lnode] == mid) left[in] = left[rnode];
      if (right[rnode] == mid + 1) right[in] = right[lnode];
      // aabb bbcd->left[rnode] = 5, right[lnode] = 2
      mmax = left[rnode] - right[lnode] + 1;
    }
    mmax = max({mmax, left[in] - l + 1, r - right[in] + 1});
    nums[in] = max({mmax, nums[lnode], nums[rnode]});
  }

  int update(int in, int l, int r, int i, char c) {
    if (l > r) return 0;
    if (l == r) {
      lc[in] = rc[in] = c;
      left[in] = l, right[in] = l;
      nums[in] = 1;
      return nums[in];
    }
    int mid = (l + r) / 2;
    if (i >= l && i <= mid) {
      update(2 * in + 1, l, mid, i, c);
    } else {
      update(2 * in + 2, mid + 1, r, i, c);
    }
    merge(in, l, mid, r);
    return nums[in];
  }
};
class Solution {
 public:
  vector<int> longestRepeating(string s, string queryCharacters,
                               vector<int>& queryIndices) {
    SegmentTree root(s);
    int n = queryCharacters.size();
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      ans[i] =
          root.update(0, 0, s.size() - 1, queryIndices[i], queryCharacters[i]);
    }
    return ans;
  }
};