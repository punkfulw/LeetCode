// OJ: https://leetcode.com/problems/minimum-time-visiting-all-points/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans {};
        int size = points.size();
        
        for (int i = 0; i < size - 1; i++){
            int x1 = points[i].at(0);
            int y1 = points[i].at(1);
            int x2 = points[i+1].at(0);
            int y2 = points[i+1].at(1);
            
            ans += max(abs(x1 - x2), abs(y1 - y2));
        }
        return ans;
    }
};
