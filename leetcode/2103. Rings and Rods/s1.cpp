// OJ: https://leetcode.com/problems/rings-and-rods/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countPoints(string rings) {
        int cnt[10][3] = {}, ans = 0;
        for (int i = 0; i < rings.size(); i += 2){
            char color = rings[i], pos = rings[i + 1];
            if (color == 'B')
                cnt[pos - '0'][0] = 1;
            else if (color == 'R')
                cnt[pos - '0'][1] = 1;
            else 
                cnt[pos - '0'][2] = 1;
        }
        
        for (int i = 0; i < 10; i++){
            int cur = 0;
            for (int j = 0; j < 3; j++)
                cur += cnt[i][j];
            if (cur == 3)
                ans++;
        }
        return ans;
    }
};
