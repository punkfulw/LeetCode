// OJ: https://leetcode.com/problems/4sum/
// Author: github.com/punkfulw
// Time: O(N^3)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 4)
            return ans;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-3; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if (nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;
            for (int j = i+1; j < n-2; j++){
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if (nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) continue;
                int l = j + 1, r = n - 1;
                while (l < r){
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum < target) l++;
                    else if (sum > target) r--;
                    else{
                        vector<int> quad = {nums[i], nums[j], nums[l], nums[r]};
                        ans.push_back(quad);
                        while (l < r && nums[r] == nums[r-1]) r--;
                        while (l < r && nums[l] == nums[l+1]) l++;
                        do{l++;}while(nums[l] == nums[l-1] && l < r);
                        do{r--;}while(nums[r] == nums[r+1] && l < r);
                    }
                }
            }
        }
        return ans;
    }
};
