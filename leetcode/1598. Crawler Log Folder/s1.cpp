// OJ: https://leetcode.com/problems/crawler-log-folder/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;
        for (auto s: logs){
            if (s == "../")
                level = max(0, level-1);
            else if (s == "./")
                continue;
            else
                level++;  
        }
        return level;
    }
};
