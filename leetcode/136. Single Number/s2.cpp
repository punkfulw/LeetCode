// OJ: https://leetcode.com/problems/single-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> cnt;
        int ans = 0;
        
        for (int i: nums){
            if (cnt.count(i) == 0){
                cnt.insert(i);
                ans += i;
            }
            else
                ans -= i;
        }
        return ans;
    }
};
