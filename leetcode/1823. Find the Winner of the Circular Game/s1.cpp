// OJ: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> q(n);
        
        for (int i = 1; i <= n; i++)
            q[i-1] = i;
        int idx = 0;
        while (n != 1)
        {
            int step = k - 1;
            step %= n;
            idx = (idx + n + step) % n;
            q.erase(q.begin() + idx);
            n--;
        }
        return q[0];    
    }
};
