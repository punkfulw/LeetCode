// OJ: https://leetcode.com/problems/rotating-the-box/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/1861.%20Rotating%20the%20Box/README.md
// Time: O(NM)
// Space: O(1)
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> ans(m, vector<char> (n, '.'));
        for (int i = 0; i < n; i++){
            int write = m - 1;
            for (int j = m - 1; j >= 0; j--){
                if (box[i][j] == '*'){
                    ans[j][n - i - 1] = '*';
                    write = j - 1;
                }
                else if (box[i][j] == '#')
                    ans[write--][n - i - 1] = '#';
            }
        }
        return ans;
    }
};
