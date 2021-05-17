// OJ: https://leetcode.com/problems/unique-number-of-occurrences/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp{};
        unordered_set<int> s{};
        
        for (int i: arr){
            mp[i]++;
        }
        for (auto p: mp){
            if (s.count(p.second))
                return false;
            s.insert(p.second);
        }
        return true;
    }
};
