// OJ: https://leetcode.com/problems/remove-stones-to-minimize-the-total/
// Author: github.com/punkfulw
// Time: O((N + K) * logN)
// Space: O(N)
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq (piles.begin(), piles.end());
        while (k > 0){
            int cur = pq.top();
            pq.pop();
            cur = (cur + 1) / 2;
            pq.push(cur);
            k--;
        }
        int ans = 0;
        while (!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
