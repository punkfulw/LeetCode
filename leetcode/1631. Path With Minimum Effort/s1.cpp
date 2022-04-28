// OJ: https://leetcode.com/problems/path-with-minimum-effort/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/path-with-minimum-effort/discuss/910417/C%2B%2B-Dijkstra-priority_queue
// Time: O(MNlog(MN))
// Space: O(MN)
class Solution {
public:
    int dirs[5] = {0, 1, 0, -1, 0};
    
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        vector<vector<int>> rec(n, vector<int>(m, INT_MAX));
        auto cmp = [&] (const array<int, 3> &p1, const array<int, 3> &p2) { return p1[0] >= p2[0]; };
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp)> pq(cmp);
        
        pq.push({0, 0, 0});
        rec[0][0] = 0;
        while (!pq.empty())
        {
            auto [cost, i, j] = pq.top();
            pq.pop();
            if (i == n - 1 && j == m - 1)
                break;
            for (int k = 0; k < 4; k++)
            {
                int r = i + dirs[k], c = j + dirs[k + 1];
                if (r < 0 || r >= n || c < 0 || c >= m) continue;
                int newCost = max(rec[i][j], abs(h[i][j] - h[r][c]));
                if (newCost < rec[r][c])
                {
                    rec[r][c] = newCost;
                    pq.push({newCost, r, c});
                }
            }
        }
        return rec[n - 1][m - 1];
    }
};
