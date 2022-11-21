// OJ: https://leetcode.com/problems/maximize-distance-to-closest-person/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = 0, n = seats.size(), cnt = 0;
        for (int i = 0, start = 1; i < n; i++){
            if (seats[i] == 0)
                cnt++;
            else{
                if (start)
                    ans = max(ans, cnt);
                else 
                    ans = max(ans, (cnt + 1) / 2);
                cnt = 0;
                start = 0;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};
