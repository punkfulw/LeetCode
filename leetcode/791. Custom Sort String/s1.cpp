// OJ: https://leetcode.com/problems/custom-sort-string/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/custom-sort-string/discuss/116556/Two-Lines-C%2B%2B
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    string customSortString(string order, string str) {
        map<char, int> map;
        for (int i = 0; i < order.size(); i++)
            map[order[i]] = i+1;
        
        sort(str.begin(), str.end(), [&](char a, char b) { return map[a] < map[b]; });
        return str;
    }
};
