// OJ: https://leetcode.com/problems/search-suggestions-system/
// Author: github.com/punkfulw
// Time: O(MlogM) 
// Space: O(N)
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = searchWord.size();
        int m = products.size();
        vector<vector<string>> ans(n);
        sort(products.begin(), products.end());

        for (int i = 0; i < n; i++){
            string s = searchWord.substr(0, i+1);
            int n = 3;
            for (int j = 0; j < m; j++){
                if (products[j].substr(0,i+1) == s){
                    n--;
                    ans[i].push_back(products[j]);
                }
                if (n == 0)
                    break;
            }
        }
        return ans;
    }
};
