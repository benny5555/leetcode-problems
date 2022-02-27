#include <bits/stdc++.h>
using namespace std;
int rand7() {
    return 0;
}
class Solution {
public:
    int rand10() {
        int x;
        do {
            x = ((rand7() - 1) * 7 + rand7() - 1);
        } while (x > 39);
        x %= 10;
        return x + 1;
    }
};