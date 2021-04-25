// OJ: https://leetcode.com/problems/sum-of-digits-in-base-k/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1) 
class Solution {
public:
    int sumBase(int n, int k) {
        int ans {};
        
        while (n >= k){
            int add = n % k;
            n /= k;
            ans += add; 
        }
        return ans + n;
    }
};
