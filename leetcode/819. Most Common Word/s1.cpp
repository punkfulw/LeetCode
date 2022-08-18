// OJ: https://leetcode.com/problems/most-common-word/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(W)
class Solution {
public:
    string mostCommonWord(string para, vector<string>& banned) {
        int n = para.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < n;){
            string s = "";
            while (i < n && isalpha(para[i])) 
                s.push_back(tolower(para[i++]));
            while (i < n && !isalpha(para[i])) 
                i++;
            mp[s]++;
        }
        for (auto b: banned)
            mp[b] = 0;
        int mx = 0;
        string ans;
        for (auto p: mp)
            if (p.second > mx){
                mx = p.second;
                ans = p.first;
            }
        return ans;
    }
};
