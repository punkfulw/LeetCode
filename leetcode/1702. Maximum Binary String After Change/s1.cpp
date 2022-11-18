// OJ: https://leetcode.com/problems/maximum-binary-string-after-change/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string maximumBinaryString(string s) {
        int n = s.size(), head = 0, zero = count(s.begin(), s.end(), '0');
        for (auto &i: s){
            if (i == '0')
                break;
            head++;
        }
        if (zero < 2)
            return s;
        return string(zero - 1 + head, '1') + "0" + string(n - zero - head, '1');
    }
};
