// OJ: https://leetcode.com/problems/happy-number/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/happy-number/discuss/56917/My-solution-in-C(-O(1)-space-and-no-magic-math-property-involved-)
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int helper(int n){
        int cur = 0;
        while (n > 0){
            int tmp = (n % 10);
            cur +=  tmp * tmp;
            n /= 10;
        }
        return cur;
    }
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do{
            slow = helper(slow);
            fast = helper(helper(fast));
            if (fast == 1)
                return true;
        }while (slow != fast);
        return false;
    }
};
