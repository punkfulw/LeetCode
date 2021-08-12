// OJ: https://leetcode.com/problems/combinations/
// Author: github.com/punkfulw
// Time: O(K)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        
        vector<int> index(k);
        iota(index.begin(), index.end(), 1);
        
        while (index[0] < n - k + 2){
            vector<int> cur;
            for (auto i: index)
                cur.push_back(i);
            ans.push_back(cur);
            for (int i = k-1; i >= 0; i--){
                if (i > 0 && index[i] == n - k + i + 1)
                    continue;
                ++index[i++];     
                for (; i < k; i++)
                    index[i] = index[i-1] + 1;
                break;
            }
        }
        return ans;
    }
};
