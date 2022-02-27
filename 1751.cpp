#include <bits/stdc++.h>
using namespace std;

class Solution1 {
    vector<vector<int>> dp;
    int dfs(vector<vector<int>> &events, int start, int k) {
        if (start >= events.size() || k <= 0) return 0;
        if (dp[start][k] != -1) return dp[start][k];
        auto next = upper_bound(events.begin(), events.end(), events[start][1], [](int time, vector<int> &v) {
                        return time < v[0];
                    })
                    - events.begin();
        return dp[start][k] = max(
                   dfs(events, start + 1, k),
                   events[start][2] + dfs(events, next, k - 1));
    }

public:
    int maxValue(vector<vector<int>> &events, int k) {
        dp = vector<vector<int>>(events.size(), vector<int>(k + 1, -1));
        sort(events.begin(), events.end());
        return dfs(events, 0, k);
    }
};

class Solution {
public:
    int maxValue(vector<vector<int>> &events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        for (int i = 1; i <= n; ++i) {
            int start = events[i - 1][0];
            int pre = -1, r = i - 1;
            while (pre < r) {
                int mid = (pre + r + 1) / 2;
                if (events[mid][1] >= start)
                    r = mid - 1;
                else
                    pre = mid;
            }
            ++pre;
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[pre][j - 1] + events[i - 1][2]);
            }
        }
        return dp[n][k];
    }
};

int main() {
    vector<vector<int>> events{{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
    Solution solution;
    cout << solution.maxValue(events, 2);
    return 0;
}