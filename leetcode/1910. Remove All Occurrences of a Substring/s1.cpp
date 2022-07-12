// OJ: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    string removeOccurrences(string s, string part) {
        auto pos = s.find(part);
        while (pos != string::npos){
            s.erase(pos, part.size());
            pos = s.find(part);
        }
        return s;
    }
};
