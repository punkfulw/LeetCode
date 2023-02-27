// OJ: https://leetcode.com/problems/construct-quad-tree/
// Author: github.com/punkfulw
// Time: O(log_4^N * N^2)
// Space: O(log_4^N)
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int same = 1, val = grid[0][0], n = grid.size();
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] != val)
                    same = 0;
        Node* node = new Node();
        if (same){
            node->isLeaf = true;
            node->val = val;
        }
        else {
            vector<vector<int>> tl(n / 2), tr(n / 2), bl(n / 2), br(n / 2);
            
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++){
                    if (i < n / 2 && j < n / 2)
                        tl[i].push_back(grid[i][j]);
                    else if (i < n / 2 && j >= n / 2)
                        tr[i].push_back(grid[i][j]);
                    else if (i >= n / 2 && j < n / 2)
                        bl[i - n / 2].push_back(grid[i][j]);
                    else if (i >= n / 2 && j >= n / 2)
                        br[i - n / 2].push_back(grid[i][j]);
                }
            
            node->topLeft = construct(tl);
            node->topRight = construct(tr);
            node->bottomLeft = construct(bl);
            node->bottomRight = construct(br);
            node->isLeaf = false;
        }
        return node;
            
    }
};
