// OJ: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int aver = nums[(n)/2];
        
        int ans = 0;
        for (int i: nums){
            ans += (abs(i - aver)); 
            cout << i << " " << ans << endl;
        }
        return ans;
    }
};
