#include <bits/stdc++.h>
using namespace std;
#include "leetcode.h"
class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        auto cur = head, oddHead = new ListNode(), evenHead = new ListNode(), odd = oddHead, even = evenHead;
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
        odd->next = 0;
        delete oddHead, evenHead;
        return head;
    }
};