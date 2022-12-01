// OJ: https://leetcode.com/problems/find-and-replace-in-string/
// Author: github.com/punkfulw
// Time: O(N^N + KlogK)
// Space: O(K)
class Solution {
public:
    bool check(string &s, int idx, string &ss){
        if (idx + ss.size() > s.size())
            return false;
        for (int i = 0; i < ss.size(); i++)
            if (s[idx + i] != ss[i])
                return false;
        return true;
    }
    string findReplaceString(string s, vector<int>& idxs, vector<string>& srs, vector<string>& tars) {
        int k = idxs.size();
        map<int, pair<string, string>> mp;
        
        for (int i = 0; i < k; i++){
            int idx = idxs[i];
            string ss = srs[i], tar = tars[i];
            mp[-idx] = {ss, tar};
        }
        
        for (auto &p: mp){
            int idx = -p.first;
            string ss = p.second.first, tar = p.second.second;
            if (!check(s, idx, ss))
                continue;
            string head = s.substr(0, idx), tail = s.substr(idx + ss.size());
            s = head + tar + tail;
        }
        return s;
    }
};
