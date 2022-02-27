#include <bits/stdc++.h>
using namespace std;
//2^n, n = target.size();
//bitmask: 11111 : apple
//         11001: ap2e
//         00000: 5
/*target.length == m
dictionary.length == n
1 <= m <= 21
0 <= n <= 1000
1 <= dictionary[i] <= 100
log2(n) + m <= 21 if n > 0   ------->2^(logn + m) <= 21 ------> 2^m * n <= 21;
长度不同的话根本不会有冲突。
*/

class Solution {
private:
    int n, state, mmin, minab, cand;
    vector<int> dict;
    void dfs(int bit, int mask) {
        //mask: 0代表缩写，1代表将这个字母输出出来。
        if (bit >= state) return;
        int len = abbrLen(mask);
        if (len >= mmin) return;
        bool match = true;
        for (int d : dict) {
            if (!(mask & d)) {
                match = false;
                break;
            }
        }
        //只要有任意一个位置上缩写后target和word不同。
        if (match) {
            mmin = len;
            minab = mask;
        } else {
            for (int i = bit; i < state; i <<= 1) {
                if (cand & i) dfs(i << 1, mask + i);
            }
        }
    }
    int abbrLen(int mask) {
        int ans = n;
        for (int i = 3; i < state; i <<= 1) {
            if (!(i & mask)) --ans;
        }
        return ans;
    }

public:
    string minAbbreviation(string target, vector<string> &dictionary) {
        n = target.size(), state = 1 << n, mmin = INT_MAX, minab = 0, cand = 0;
        for (auto &s : dictionary) {
            if (n != s.size()) continue;
            int word = 0;
            for (int i = 0; s[i]; ++i) {
                if (s[i] != target[i]) word |= 1 << i;
            }
            //word & cand：在i位上target和dictionary里面的word不同。1代表不同。
            cand |= word;
            dict.push_back(word);
        }
        dfs(1, 0);
        string ans;
        for (int i = 0; i < n;) {
            if (minab & (1 << i)) {
                ans.push_back(target[i++]);
            } else {
                int j = i;
                while (i < n && !(minab & (1 << i))) ++i;
                ans += to_string(i - j);
            }
        }
        return ans;
    }
};

int main() {
    string target = "apple";
    vector<string> dictionary{"alade", "alain", "amber"};
    Solution solution;
    cout << solution.minAbbreviation(target, dictionary) << endl;
    return 0;
}