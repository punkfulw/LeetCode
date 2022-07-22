// OJ: https://leetcode.com/problems/alphabet-board-path/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    unordered_map<char, pair<int, int>> mp;
    
    void sol(int &x, int &y, char ch, string &ans){
        int r = mp[ch].first, c = mp[ch].second;
        int dify = x - r, difx = c - y;
        x = r, y = c;
        if (dify < 0){
            // down
            if (difx > 0)
                ans += string(difx, 'R');
            else if (difx < 0)
                ans += string(-difx, 'L');
            ans += string(-dify, 'D');
        }
        else {
            // top
            ans += string(dify, 'U');
            if (difx > 0)
                ans += string(difx, 'R');
            else if (difx < 0)
                ans += string(-difx, 'L');
        }
        ans += '!';
        return;
    }
    
    string alphabetBoardPath(string target) {
        string ans;
        int x = 0, y = 0;
        char c = 'a';
        
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 5 && c <= 'z'; j++, c++)
                mp[c] = {i, j};
        for (auto ch: target)
            sol(x, y, ch, ans);
        return ans;
    }
};
