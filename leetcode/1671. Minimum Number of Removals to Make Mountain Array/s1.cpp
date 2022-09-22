// OJ: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    void build(vector<int> &arr, int i, int end, int dir, vector<int> &nums){
        vector<int> stk;
        while (i != end){
            if (stk.empty() || nums[i] > stk.back()){
                stk.push_back(nums[i]);
                arr[i] = stk.size() - 1;
            }
            else{
                auto it = lower_bound(stk.begin(), stk.end(), nums[i]);
                arr[i] = it - stk.begin();
                *it = nums[i];
            } 
            i += dir;
        }
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX / 2;
        vector<int> left(n), right(n);
        
        build(left, 0, n, 1, nums);
        build(right, n - 1, -1, -1, nums);
        
        for (int i = 0; i < n; i++){
            if (left[i] == 0 || right[i] == 0) continue;
            int cur = (i - left[i]) + ((n - i - 1) - right[i]);
            ans = min(ans, cur);
        }
        
        return ans;        
    }
};
