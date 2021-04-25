// OJ: https://leetcode.com/problems/increasing-decreasing-string
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string sortString(string s) {
        string ans;
        vector<int> v(26, 0);
        
        for (auto c: s){
            v[c-'a']++;
        }
        while (ans.size() != s.size()){
            for (int i = 0; i < 26; i++){
                if(v[i]){
                    ans += 'a' + i;
                    v[i]--;
                }
            }
            for (int i = 25; i >= 0; i--){
                if (v[i]){
                    ans += 'a' + i;
                    v[i]--;
                }
            }
        }
        return ans;
    }
};
