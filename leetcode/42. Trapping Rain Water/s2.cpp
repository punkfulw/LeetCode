// OJ: https://leetcode.com/problems/trapping-rain-water/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/trapping-rain-water/discuss/17357/Sharing-my-simple-c%2B%2B-code%3A-O(n)-time-O(1)-space
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int trap(vector<int>& h) {
        int left = 0, right = h.size()-1;
        int leftmax = 0, rightmax = 0;
        int ans = 0;
        
        while (left < right){
            if (h[left] <= h[right]){
                if (h[left] >= leftmax)
                    leftmax = h[left];
                else
                    ans += leftmax - h[left];
                left++;
            }
            else{
                if (h[right] >= rightmax)
                    rightmax = h[right];
                else
                    ans += rightmax - h[right];
                right--;
            }
        }
        return ans;
    }
};
