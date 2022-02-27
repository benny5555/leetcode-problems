#include <bits/stdc++.h>
#include "leetcode.h"
using namespace std;
class Solution {
private:
    ListNode *head;

public:
    Solution(ListNode *head) :
        head(head) {
    }

    int getRandom() {
        int cnt = 0;
        auto cur = head;
        int ans = 0;
        while (cur) {
            if (rand() % ++cnt == 0) {
                ans = cur->val;
            }
            cur = cur->next;
        }
        return ans;
    }
};