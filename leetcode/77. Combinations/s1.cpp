// OJ: https://leetcode.com/problems/combinations/
// Author: github.com/punkfulw
// Time: O(K!)
// Space: O(K)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int mask = 1 << n;
        vector<vector<int>> ans;
        
        for (int no = 1; no < mask; no++){
            int i = 1;
            int num = no;
            vector<int> cur;
            while (num){
                if (num & 1)
                    cur.push_back(i);
                num >>= 1;
                i++;
            }
            if (cur.size() == k)
                ans.push_back(cur);
        }
        return ans;
    }
};
