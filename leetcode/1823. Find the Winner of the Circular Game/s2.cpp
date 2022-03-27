// OJ: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
// Author: github.com/punkfulw
// Time: O(NK)
// Space: O(N)
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; i++)
            q.push(i);
        while (n != 1)
        {
            int step = k - 1;
            step = (step + n) % n;  
            while (step--)
            {
                int p = q.front();
                q.pop();
                q.push(p); 
                
            }
            q.pop();
            n--;
        }
        return q.front();    
    }
};
