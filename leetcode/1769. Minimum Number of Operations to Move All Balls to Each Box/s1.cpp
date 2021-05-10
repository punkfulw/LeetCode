// OJ: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans (n, 0);
        
        for (int i = 0; i < n; i++){
            int num = 0;
            for (int j = 0; j < n; j++){
                if (boxes[j] == '1')
                    num += abs(j-i);
            }
            ans[i] = num;
        }
        return ans;
    }
};
