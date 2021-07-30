// OJ: https://leetcode.com/problems/count-number-of-teams/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int numTeams(vector<int>& r) {
        int ans = 0, n = r.size();
        vector<int> leftsmall(n), leftbig(n), rightsmall(n), rightbig(n);
        for(int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (r[j] < r[i])
                    leftsmall[i]++;
                else if(r[j] > r[i])
                    leftbig[i]++;
            }
        }
        for(int i = n-2; i >= 0; i--){
            for (int j = n-1; j > i; j--){
                if (r[j] < r[i])
                    rightsmall[i]++;
                else if(r[j] > r[i])
                    rightbig[i]++;
            }
        }
        for (int i = 0; i < n; i++)
            ans += rightsmall[i] * leftbig[i] + leftsmall[i] * rightbig[i];
        return ans;
    }
};
