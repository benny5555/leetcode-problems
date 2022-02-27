#include <bits/stdc++.h>
#include "leetcode.h"
using namespace std;
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next) return;
        auto tail = head, fast = head;
        while (fast->next && fast->next->next) {
            tail = tail->next;
            fast = fast->next->next;
        }
        auto next = tail->next;
        tail->next = nullptr;
        tail = next;
        auto dummy = new ListNode(0, nullptr);
        ListNode *cur = tail;
        while (cur) {
            next = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = next;
        }
        tail = dummy->next;
        delete dummy;
        while (head && tail) {
            auto headnext = head->next;
            head->next = tail;
            head = headnext;
            auto tailnext = tail->next;
            tail->next = head;
            tail = tailnext;
        }
    }
};