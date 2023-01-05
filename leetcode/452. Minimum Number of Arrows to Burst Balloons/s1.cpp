// OJ: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size(), shot = points[0][1], ans = 1;
        
        for (int i = 1; i < n; i++){
            int start = points[i][0], end = points[i][1];
            
            if (start > shot){
                ans++;
                shot = end;
            }
            else 
                shot = min(shot, end);

        }
        return ans;
    }
};
