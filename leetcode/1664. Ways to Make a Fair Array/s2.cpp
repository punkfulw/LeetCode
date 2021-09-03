// OJ: https://leetcode.com/problems/ways-to-make-a-fair-array/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/ways-to-make-a-fair-array/discuss/944355/C%2B%2B-O(N)-Time-O(1)-Space-PrefixSuffix-Sum
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        int evenSuffix = 0, evenPrefix = 0, oddSuffix = 0, oddPrefix = 0;
        for (int i = 0; i < n; i++){
            if (i % 2 == 0) 
                evenSuffix += nums[i];
            else 
                oddSuffix += nums[i];
        }
        
        for (int i = 0; i < n; i++){
            if (i % 2 == 0) 
                evenSuffix -= nums[i];
            else 
                oddSuffix -= nums[i];
            cnt += (evenSuffix + oddPrefix) == (evenPrefix + oddSuffix);
            if (i % 2 == 0) 
                evenPrefix += nums[i];
            else
                oddPrefix += nums[i];
        }
        return cnt;
    }
};
