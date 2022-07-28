// OJ: https://leetcode.com/problems/product-of-array-except-self/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0, ttl = 1, n = nums.size();
        vector<int> ans(n, 0);
        for (auto i: nums){
            ttl *= i == 0 ? 1 : i;
            zero += i == 0 ? 1 : 0;
        }
        if (zero > 1) return ans;
        for (int i = 0; i < n; i++){
            if (nums[i] == 0)
                ans[i] = ttl;
            else
                ans[i] = zero ? 0 : ttl / nums[i];
        }
        return ans;
    }
};
