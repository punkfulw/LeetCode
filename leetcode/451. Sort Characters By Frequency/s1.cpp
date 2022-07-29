// OJ: https://leetcode.com/problems/sort-characters-by-frequency/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int> mp;
        for (auto c: s)
            mp[c]++;
        vector<pair<int, char>> rec;
        for (auto p: mp)
            rec.push_back({p.second, p.first});
        sort(rec.rbegin(), rec.rend());
        for (auto p: rec){
            ans += string (p.first, p.second);
        }
        return ans;
    }
};
