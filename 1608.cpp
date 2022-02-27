#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int specialArray(vector<int> &nums) {
        int cnt[105]{0};
        for (int num : nums) {
            ++cnt[num > 100 ? 100 : num];
        }
        for (int i = 100; i >= 0; --i) {
            cnt[i] += cnt[i + 1];
            if (cnt[i] == i) return i;
        }
        return -1;
    }
};