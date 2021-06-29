// OJ: https://leetcode.com/problems/palindrome-number/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/palindrome-number/discuss/5165/An-easy-c%2B%2B-8-lines-code-(only-reversing-till-half-and-then-compare)
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        stack<int> stk;
        
        int n = x;
        while (n > 0){
            stk.push(n % 10);
            n /= 10;
        }
        while (x > 0){
            //cout << stk.top();
            if (x % 10 != stk.top())
                return false;
            x /= 10;
            stk.pop();
        }
        
        return true;
    }
};
