// OJ: https://leetcode.com/problems/rotate-function/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = 0, n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++){
            ans += i * nums[i];
            sum += nums[i];
        }
        
        for (int i = n - 1, pre = ans; i > 0; i--){
            int cur = nums[i], res = sum - cur;
            pre += res - cur * (n - 1);
            ans = max(ans, pre);

        }
        return ans;
    }
};
