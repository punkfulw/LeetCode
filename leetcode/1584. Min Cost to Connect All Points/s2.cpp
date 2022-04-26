// OJ: https://leetcode.com/problems/min-cost-to-connect-all-points/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
// Ref: https://leetcode.com/problems/min-cost-to-connect-all-points/discuss/844162/C%2B%2B-Beats-100-Time-Simple-Prim's-Complexity-O(n2)-with-Pseudo-Heap
class Solution {
public:
    int dist(int x1, int y1, int x2, int y2)
    {
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        
        vector<int> mindis(n, 0);
        mindis[0] = INT_MAX;
        for (int i = 1; i < n; i++)
            mindis[i] = dist(points[0][0], points[0][1], points[i][0], points[i][1]);
        
        for (int i = 1; i < n; i++)
        {
            auto it = min_element(mindis.begin(), mindis.end());
            ans += *it;
            int index = it - mindis.begin();
            mindis[index] = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (mindis[j] == INT_MAX)
                    continue;
                mindis[j] = min(mindis[j], dist(points[index][0], points[index][1], points[j][0], points[j][1]));
            }
        }
        return ans;
    }
};
