// OJ: https://leetcode.com/problems/queries-on-a-permutation-with-key/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(M)
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ans {};
        vector<int> p {};
        
        for (int i = 1; i <= m; i++){
            p.push_back(i);
        }
        for (int i = 0; i < queries.size(); i++){
            int num = 0;
            for (int j = 0; j < m; j++){
                if (queries[i] == p[j])
                    num = j;
            }
            
            ans.push_back(num);
            int temp = p[num];
            for (int j = num; j > 0; j--){
                p[j] = p[j-1];
            }
            p[0] = temp;
        }
        return ans;
    }
};
