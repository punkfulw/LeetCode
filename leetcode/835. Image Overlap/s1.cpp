// OJ: https://leetcode.com/problems/image-overlap/
// Author: github.com/punkfulw
// Time: O(N^4)
// Space: O(1)
class Solution {
public:
    int ans = 0, n;
    void check(vector<vector<int>>& img1, vector<vector<int>>& img2, int shift_i, int shift_j){
        int cnt = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int r = i + shift_i, c = j + shift_j;
                if (r < 0 || r >= n || c < 0 || c >= n || img2[i][j] == 0 || img1[r][c] == 0)
                    continue;
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        n = img1.size();
        for (int i = -n; i < n; i++)
            for (int j = -n; j < n; j++)
                check(img1, img2, i, j);
        
        return ans;
    }
};
