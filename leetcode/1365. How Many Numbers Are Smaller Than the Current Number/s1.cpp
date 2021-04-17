// OJ: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(M) M = number of different int
// Ref: https://leetcode.com/problems/number-of-days-between-two-dates/discuss/517605/Similar-to-day-of-the-year
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> values;
        vector<int> numsCopy = nums;
        int numsSize = nums.size();
        sort(numsCopy.begin(), numsCopy.end(), greater<int>());
        for(int i = 0 ; i < numsSize; i++){
            values[numsCopy[i]] = ((numsSize-1) - i);
        }
        for(int i = 0; i < numsSize; i++) {
            nums[i] = values[nums[i]];
        }
        return nums;     
    } 
};
