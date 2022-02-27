#include <bits/stdc++.h>
#include "leetcode.h"
using namespace std;

class Solution {
private:
    void my_reverse(ListNode *head, ListNode *tail) {
        auto dummy = new ListNode(0, tail);
        ListNode *cur = head, *next;
        while (cur != tail) {
            next = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = next;
        }
        delete dummy;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 1) return head;
        auto dummy = new ListNode(0, head);
        ListNode *pre = dummy, *cur = dummy;
        int temp = 0;
        while (cur) {
            ++temp;
            cur = cur->next;
            if (!cur) break;
            if (temp == k) {
                temp = 0;
                auto next_start = pre->next;
                pre->next = cur;
                my_reverse(next_start, cur->next);
                pre = next_start;
                cur = pre;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main() {
    auto head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution solution;
    solution.reverseKGroup(head, 2);
    return 0;
}