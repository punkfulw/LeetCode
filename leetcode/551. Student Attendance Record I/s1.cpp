// OJ: https://leetcode.com/problems/student-attendance-record-i/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkRecord(string s) {
        int late = 0, absent = 0;
        for (auto c: s){
            if (c == 'A')
                absent++;
            if (c == 'L')
                late++;
            else
                late = 0;
            if (late >= 3)
                return false;
        }
        return absent < 2;
    }
};
