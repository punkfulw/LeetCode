// OJ: https://leetcode.com/problems/angle-between-hands-of-a-clock/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;
        double h = (hour * 60.0 + minutes) / 2, m = minutes * 6;
        if (h < m)
            swap(h, m);
        if (h - m > 180)
            return 360 - h + m;
        return h - m;
    }
};
