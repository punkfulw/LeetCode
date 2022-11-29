// OJ: https://leetcode.com/problems/reorder-data-in-log-files/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        map<string, vector<string>> let;
        vector<string> ans, dig;
        
        for (auto log: logs){
            stringstream ss;
            string s, head, tail;
            ss << log;
            ss >> head;
            int isD;            
            while (ss >> s){
                if (isdigit(s[0]))
                    isD = 1;
                else 
                    isD = 0;
                tail += s + " ";
            }
            tail.pop_back();
            if (isD)
                dig.push_back(head + " " + tail);
            else 
                let[tail].push_back(head);
        }
        
        for (auto p: let){
            sort(p.second.begin(), p.second.end());
            for (auto tail: p.second)
                ans.push_back(tail + " " + p.first);
        }
        
        for (auto s: dig)
            ans.push_back(s);
        return ans;
    }
};
