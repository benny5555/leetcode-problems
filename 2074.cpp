#include <bits/stdc++.h>
#include "leetcode.h"
using namespace std;
class Solution {
private:
    void myreverse(ListNode *head, ListNode *tail) {
        auto dummy = new ListNode(0, tail);
        ListNode *cur = head, *next = nullptr;
        while (cur != tail) {
            next = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = next;
        }
        delete dummy;
    }

public:
    ListNode *reverseEvenLengthGroups(ListNode *head) {
        if (!head) return head;
        auto dummy = new ListNode(0, head);
        auto pre = dummy, cur = dummy;
        int size = 1, cnt = 0;
        while (cur) {
            ++cnt;
            cur = cur->next;
            if (!cur) break;
            if ((cnt & 1) == 0 && cur->next == nullptr) {
                auto temp = pre->next;
                pre->next = cur;
                myreverse(temp, cur->next);
                break;
            }
            if (cnt == size) {
                ListNode *next_pre = cur;
                if ((cnt & 1) == 0) {
                    next_pre = pre->next;
                    pre->next = cur;
                    myreverse(next_pre, cur->next);
                }
                pre = next_pre;
                cur = next_pre;
                ++size;
                cnt = 0;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main() {
    auto head = new ListNode(1, new ListNode(1, new ListNode(0, new ListNode(6))));
    Solution solution;
    solution.reverseEvenLengthGroups(head);
    return 0;
}