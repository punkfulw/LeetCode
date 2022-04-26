// OJ: https://leetcode.com/problems/min-cost-to-connect-all-points/
// Author: github.com/punkfulw
// Time: O(K * log(N^2))
// Space: O(N^2)
// Ref: https://leetcode.com/problems/min-cost-to-connect-all-points/discuss/843940/C%2B%2B-MST%3A-Kruskal-%2B-Prim's-%2B-Complete-Graph
class Solution {
public:
    int union_find(vector<int> &parent, int i)
    {
        return parent[i] < 0 ? i : parent[i] = union_find(parent, parent[i]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& ps) {
        int ans = 0, n = ps.size();
        
        vector<array<int, 3>> arr;
        vector<int> parent(n, -1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr.push_back({abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]), i, j});
        
        make_heap(arr.begin(), arr.end(), greater<array<int, 3>>());
        while (!arr.empty())
        {
            pop_heap(arr.begin(), arr.end(), greater<array<int, 3>>());
            auto [dis, i, j] = arr.back();
            arr.pop_back();
            i = union_find(parent, i);
            j = union_find(parent, j);
            if (i != j)
            {
                parent[i] += parent[j];
                parent[j] = i;
                ans += dis;
                if (parent[i] == -n)
                    break;
            }
        }
        return ans;
    }
};
