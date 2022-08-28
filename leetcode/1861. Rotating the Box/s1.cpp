// OJ: https://leetcode.com/problems/rotating-the-box/
// Author: github.com/punkfulw
// Time: O(NMM)
// Space: O(1)
class Solution {
public:
    int n, m;
    
    void sol(vector<char> &row){
        row.push_back('*');
        int start = 0, cnt = 0;
        for (int j = 0; j <= m; j++){
            char c = row[j];
            if (c == '*'){
                if (cnt){
                    for (int k = j - 1; k >= start; cnt--, k--){
                        if (cnt > 0)
                            row[k] = '#';
                        else
                            row[k] = '.';
                    }
                }
                cnt = 0;
                start = j + 1;
            }
            else if (c == '#')
                cnt++;   
        }
        row.pop_back();
    }
    
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        n = box.size(), m = box[0].size();
        for (int i = 0; i < n; i++)
            sol(box[i]);
        
        vector<vector<char>> ans(m, vector<char> (n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans[j][n - i - 1] = box[i][j];
        return ans;
    }
};
