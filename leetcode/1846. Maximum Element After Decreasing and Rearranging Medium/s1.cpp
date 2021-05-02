// OJ: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        int ans = 1, i = 1;
        
        for (int num: arr){
            ans = min(i, num);
            if (num >= i)
                i++;
        }
        return ans;
    }
};
