// OJ: https://leetcode.com/problems/maximum-gap/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        priority_queue<int> q;
        int dif = 0;
        
        for (auto i: nums)
            q.push(i);
        while (!q.empty()){
            int a = q.top();
            q.pop();
            if (!q.empty()){
                int b = q.top();
                dif = max(dif, a-b);
            }
        }
        return dif;
    }
};
