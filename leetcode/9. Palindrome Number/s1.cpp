// OJ: https://leetcode.com/problems/palindrome-number/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/palindrome-number/discuss/5165/An-easy-c%2B%2B-8-lines-code-(only-reversing-till-half-and-then-compare)
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x > 0 && x % 10 == 0))
            return false;
        int n = 0;
        while (x > n){
            n = n * 10 + x % 10;
            x /= 10;
        }
        return n == x || n/10 == x;
    }
};
