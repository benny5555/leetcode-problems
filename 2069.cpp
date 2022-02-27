#include <bits/stdc++.h>
using namespace std;
class Robot {
private:
    int dir[4][2]{1, 0, 0, 1, -1, 0, 0, -1}, d, w, h, perimeter, x, y;
    string direction[4]{"East", "North", "West", "South"};
    int func() {
        if (!d)
            return w - 1 - x;
        if (d == 1)
            return h - 1 - y;
        if (d == 2)
            return x;
        return y;
    }

public:
    Robot(int width, int height) :
        w(width), h(height), perimeter(2 * (w + h - 2)) {
        d = x = y = 0;
    }

    void step(int num) {
        if (num >= perimeter) {
            num %= perimeter;
            if (x == 0 && y == 0 && d == 0)
                d = 3;
        }
        while (num) {
            int cnt = min(num, func());
            num -= cnt;
            x += (dir[d][0]) * cnt;
            y += dir[d][1] * cnt;
            if (num)
                d = (d + 1) % 4;
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return direction[d];
    }
};
int main() {
    return 0;
}