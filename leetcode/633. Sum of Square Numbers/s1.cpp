// OJ: https://leetcode.com/problems/sum-of-square-numbers/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0, right = sqrt(c);
        while (left <= right){
            long cur = left * left + (long)right * right;
            if (cur == c)
                return true;
            else if (cur < c)
                left++;
            else 
                right--;
        }
        return false;
    }
};
