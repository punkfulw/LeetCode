// OJ: https://leetcode.com/problems/furthest-building-you-can-reach/
// Author: github.com/punkfulw
// Time: O(NlogL)
// Space: O(L)
class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        int n = h.size(), i = 0;
        priority_queue<int> pq;
        
        for (; i < n - 1; i++){
            int dif = h[i + 1] - h[i];
            if (dif <= 0) 
                continue;
            pq.push(-dif);
            while (pq.size() > ladders){
                int change = pq.top(); pq.pop();
                bricks += change;
            }
            if (bricks < 0)
                break;
        }
        return i;
    }
};
