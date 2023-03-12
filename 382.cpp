#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
  ListNode* head;

 public:
  Solution(ListNode* h) : head(h) {}

  int getRandom() {
    int ans = 0;
    auto cur = head;
    while (cur) {
      if (rand() % ++cnt == 0) {
        ans = cur->val;
      }
      cur = cur->next;
    }
    return ans;
  }
};
