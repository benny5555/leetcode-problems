#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  int pairSum(ListNode* head) {
    auto slow = head, fast = head;
    int ans = 0;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode *temp = nullptr, *prev = nullptr;
    while (slow) {
      temp = slow->next;
      slow->next = prev;
      prev = slow;
      slow = temp;
    }
    while (prev) {
      ans = max(ans, head->val + prev->val);
      prev = prev->next;
      head = head->next;
    }
    return ans;
  }
};