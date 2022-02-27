#include <bits/stdc++.h>
#include "leetcode.h"
using namespace std;
class Solution {
    void my_reverse(ListNode *head, ListNode *tail) {
        auto dummy = new ListNode(0, tail);
        ListNode *cur = head, *next;
        while (cur != tail) {
            next = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = next;
        }
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        auto dummy = new ListNode(0, head);
        ListNode *start, *end, *pre_start;
        auto cur = dummy;
        while (--left) {
            --right;
            cur = cur->next;
        }
        start = cur->next, pre_start = cur;
        while (--right > 0) {
            cur = cur->next;
        }
        end = cur->next;
        pre_start->next = end;
        my_reverse(start, end->next);
        head = dummy->next;
        delete dummy;
        return head;
    }
};