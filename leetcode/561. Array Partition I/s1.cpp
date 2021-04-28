// OJ: https://leetcode.com/problems/array-partition-i/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum {};
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i+=2){
            sum += min(nums[i], nums[i+1]);           
        }
        return sum;
    }
};
