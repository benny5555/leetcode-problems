#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(vector<int> &startPos, vector<int> &homePos, vector<int> &rowCosts, vector<int> &colCosts) {
        int i = startPos[0], j = startPos[1];
        int ex = homePos[0], ey = homePos[1];
        int ans = 0;
        while (i != ex) {
            i += (ex - i) / abs(ex - i);
            ans += rowCosts[i];
        }
        while (j != ey) {
            j += (ey - j) / abs(ey - i);
            ans += colCosts[j];
        }
        return ans;
    }
};