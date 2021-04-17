// OJ: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
// Author: github.com/punkfulw
// Time: O(N.length) 
// Space: O(1)
class Solution {
public:
    int subtractProductAndSum(int n) {
        int p = 1;
        int s = 0;
        while (n >= 1){
            p = p * (n % 10);
            s = s + (n % 10);
            n /= 10;
        }
        return p-s;            

    }
};
