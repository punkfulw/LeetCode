// OJ: https://leetcode.com/problems/ipo/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(), i = 0;
        priority_queue<int> pq;
        vector<pair<int, int>> nums(n);
        
        for (int i = 0; i < n; i++)
            nums[i] = {capital[i], profits[i]};
        sort(nums.begin(), nums.end());

        while (i < n && k){
            while (i < n && w >= nums[i].first)
                pq.push(nums[i++].second);
            if (pq.empty())
                break;
            w += pq.top();
            pq.pop();
            k--;
        }
        while (k-- && pq.size()){
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
