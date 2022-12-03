// OJ: https://leetcode.com/problems/sort-characters-by-frequency/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    string frequencySort(string s) {
        int cnt[256] = {};
        
        for (auto c: s)
            cnt[c]++;
        
        sort(s.begin(), s.end(), [&](char &a, char &b){
            if (cnt[a] == cnt[b])
                return a < b;
            return cnt[a] > cnt[b];
        });
        return s;
    }
};
