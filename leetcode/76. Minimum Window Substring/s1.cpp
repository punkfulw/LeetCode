// OJ: https://leetcode.com/problems/minimum-window-substring/
// Author: github.com/punkfulw
// Time: O(N*C)
// Space: O(C) where C is the range of characters
class Solution {
public:
    string minWindow(string s, string t) {
        int mapS[128] = {}, mapT[128] = {};
        for (auto c: t) mapT[c]++;
        for (auto c: s) mapS[c]++;
        for (int i = 0; i < 128; i++)
            if (mapT[i] > mapS[i])
                return "";
        
        return check(mapT, s, t);
    }
    string check(int* mapT, string s, string t){
        int mapS[128] = {};
        int start = 0;
        string ans = s;
        for (int end = 0; end < s.size(); end++){
            mapS[s[end]]++;
            
            while (end-start+1 >= t.size() && cover(mapS, mapT)){
                mapS[s[start]]--;
                ans = ans.size() > end-start+1 ? s.substr(start, end-start+1) : ans;
                start++;
            }
        }
        return ans;
    }
    bool cover(int* mapS, int* mapT){
        for (int i = 0; i < 128; i++)
            if (mapT[i] > mapS[i])
                return false;
        return true;
    }
};
