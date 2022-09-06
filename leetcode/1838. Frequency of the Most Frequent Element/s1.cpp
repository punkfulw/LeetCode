// OJ: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        long cnt = 0, n = nums.size(), ans = 0;
        for (long i = 0, j = 0; j < n; j++){
            cnt += nums[j];
            long tar = (j - i + 1) * nums[j], dif = tar - cnt;
            while (k < dif){
                cnt -= nums[i++];
                tar = (j - i + 1) * nums[j];
                dif = tar - cnt;
            }
            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};
