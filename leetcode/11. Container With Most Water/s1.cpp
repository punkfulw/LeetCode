// OJ: https://leetcode.com/problems/container-with-most-water/
// Author: github.com/lpunkfulw
// Reference: https://leetcode.com/problems/container-with-most-water/discuss/6090/Simple-and-fast-C%2B%2BC-with-explanation
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int water = 0;
        
        while (i < j){
            int h =min(height[i], height[j]);
            water = max(water, h * (j - i));
            while (height[i] <= h && i < j) ++i;
            while (height[j] <= h && i < j) --j;
        }
        return water;
    }
};
