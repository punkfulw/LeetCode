// OJ: https://leetcode.com/problems/simplified-fractions/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int i = 1; i < n; i++){
            for (int j = i + 1; j <= n; j++){
                if (gcd(i, j) == 1){
                    string s = to_string(i) + "/" + to_string(j);
                    ans.push_back(s);
                }   
            }
        }
        return ans;
    }
};
