// OJ: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
// Author: github.com/punkfulw
// Time: O(NlogN * W)
// Space: O(NW)
class Solution {
public:
    vector<string> ans;
    void clean(string root, vector<string> &folder, int &j){
        int sz = root.size();
        while (j < folder.size() && folder[j].size() >= sz && folder[j].substr(0, sz) == root){
            if (folder[j].size() > sz && folder[j][sz] == '/')
                j++;
            else
                break;
        }
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        
        for (int i = 0; i < folder.size(); ){
            ans.push_back(folder[i]);
            int j = i + 1;
            clean(folder[i], folder, j);
            i = j;
        }
        
        return ans;
    }
};
