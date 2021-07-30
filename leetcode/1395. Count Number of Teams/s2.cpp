// OJ: https://leetcode.com/problems/count-number-of-teams/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/count-number-of-teams/discuss/554795/C%2B%2BJava-O(n-*-n)-and-O(n-log-n)
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int numTeams(vector<int>& r) {
        int ans = 0, n = r.size();
        
        for(int i = 0; i < n; i++){
            int leftsmall = 0, leftbig = 0;
            int rightsmall = 0, rightbig = 0;
            for (int j = 0; j < i; j++){
                if (r[j] < r[i])
                    leftsmall++;
                else if(r[j] > r[i])
                    leftbig++;
            }
            for (int j = n-1; j > i; j--){
                if (r[j] < r[i])
                    rightsmall++;
                else if(r[j] > r[i])
                    rightbig++;
            }
            ans += rightsmall * leftbig + leftsmall * rightbig;
        }
        return ans;
    }
};
