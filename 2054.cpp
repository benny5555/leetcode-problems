#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxTwoEvents(vector<vector<int>> &events) {
        int ans = 0, mmax = 0;
        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> que;
        sort(events.begin(), events.end());
        for (auto &e : events) {
            while (que.size() && que.top().first < e[0]) {
                if (que.top().second > mmax) mmax = que.top().second;
                que.pop();
            }
            if (mmax + e[2] > ans) ans = mmax + e[2];
            que.push({e[1], e[2]});
        }
        return ans;
    }
};