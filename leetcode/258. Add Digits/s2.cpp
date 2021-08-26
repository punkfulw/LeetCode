// OJ: https://leetcode.com/problems/add-digits/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/add-digits/discuss/68580/Accepted-C%2B%2B-O(1)-time-O(1)-space-1-Line-Solution-with-Detail-Explanations
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};
