// OJ: https://leetcode.com/problems/find-duplicate-file-in-system/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    unordered_map<string, vector<string>> mp;
    void build(string path){
        stringstream ss(path);
        string root, s;
        ss >> root;
        while (ss >> s){
            string file, content;
            file = root + "/" + s.substr(0, s.find('('));
            content = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
            mp[content].push_back(file);
        }
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        
        for (auto path: paths)
            build(path);
        
        for (auto p: mp)
            if (p.second.size() > 1)
                ans.push_back(p.second);
        
        return ans;
    }
};
