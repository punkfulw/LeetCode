// OJ: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> x;
        int n = points.size();
        int w = 0;
        
        for (int i = 0; i < n; i++){
            x.push_back(points[i][0]);
        }
        sort(x.begin(), x.end());
        
        for (int i = 0; i < x.size()-1; i++){
            w = max(w, abs(x[i]-x[i+1]));
        }
        return w;
    }
};
