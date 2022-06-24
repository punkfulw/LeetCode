// OJ: https://leetcode.com/problems/two-furthest-houses-with-different-colors/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(M)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int l = 0, n = colors.size(), r = n - 1;
        if (colors[l] != colors[r]) return r - l;
        
        int left = l + 1, right = r - 1;
        while (colors[left] == colors[l]) 
            left++;
        while (colors[right] == colors[l]) 
            right--;
        
        return max(r - left, right - l);
    }
};
