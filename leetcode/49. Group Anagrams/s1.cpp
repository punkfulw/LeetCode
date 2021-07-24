// OJ: https://leetcode.com/problems/group-anagrams/
// Author: github.com/punkfulw
// Time: O(NK)
// Space: O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (auto s: strs){
            string ori = s;
            sort(s.begin(), s.end());
            mp[s].push_back(ori);
        }
        for (auto p: mp)
            ans.push_back(p.second);
        return ans;
    }
};
