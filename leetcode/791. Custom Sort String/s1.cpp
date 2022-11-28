// OJ: https://leetcode.com/problems/custom-sort-string/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        
        for (int i = 0; i < order.size(); i++)
            mp[order[i]] = i;

        sort(s.begin(), s.end(), [&](char &a, char &b){
           return mp[a] < mp[b]; 
        });
        return s;
    }
};
