// OJ: https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size(), ans = -1, dis = INT_MAX;
        
        for (int i = 0; i < n; i++){
            if (points[i][0] == x || points[i][1] == y){
                int cnt = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (cnt < dis){
                    ans = i;
                    dis = cnt;
                }
            }
        }
        return ans;
    }
};
