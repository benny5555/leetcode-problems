#include <bits/stdc++.h>
using namespace std;
#include "leetcode.h"
class Solution {
 public:
  ListNode *oddEvenList(ListNode *head) {
    auto cur = head, evenHead = new ListNode(), oddHead = new ListNode(),
         even = evenHead, odd = oddHead;
    for (int i = 0; cur; ++i, cur = cur->next) {
      if (i & 1) {
        odd->next = cur;
        odd = odd->next;
      } else {
        even->next = cur;
        even = even->next;
      }
    }
    even->next = oddHead->next;
    odd->next = nullptr;
    return evenHead->next;
  }
};