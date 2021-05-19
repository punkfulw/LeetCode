// OJ: https://leetcode.com/problems/delete-columns-to-make-sorted
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int n = strs.size();
        int m = strs[0].size();
        
        for (int i = 0; i < m; i++){
            for (int j = 1; j < n; j++){
                if (strs[j-1][i] > strs[j][i] ){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
