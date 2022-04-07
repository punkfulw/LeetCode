// OJ: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 1, n = nums.size(), running = 1, prev;
        for (int i = 1; i < n;)
        {   
            prev = nums[i-1];
            nums[pos] = nums[i];  
            if (nums[i] == prev)
                running++;           
            else
                running = 1;
            i++; pos++;
            
            while (running == 2 && i < n && nums[i] == prev)
                i++;
            if (i >= n)
                break;
            running = 1;
            
        }
        return pos;
    }
};
