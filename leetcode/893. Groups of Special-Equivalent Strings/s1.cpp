// OJ: https://leetcode.com/problems/groups-of-special-equivalent-strings/
// Author: github.com/punkfulw
// Time: O(NMlogM) 
// Space: O(N) 
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> ans {};
        
        for (auto s: A){
            string odd {};
            string even {};
            for (int i = 0; i < s.size(); i++){
                if (i % 2 == 0)
                    even += s[i];
                else
                    odd += s[i];
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            ans.insert(even + odd);
        }
        return  ans.size();
    }
};
