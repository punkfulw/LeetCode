// OJ: https://leetcode.com/problems/maximum-performance-of-a-team/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/maximum-performance-of-a-team/discuss/539687/JavaC%2B%2BPython-Priority-Queue
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> ess;
        for (int i = 0; i < n; i++)
            ess.emplace_back(efficiency[i], speed[i]);
        sort(ess.rbegin(), ess.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        long sumS = 0, res = 0;
        for (auto [e, s]: ess){
            sumS += s;
            pq.push(s);
            if (pq.size() > k){
                sumS -= pq.top();
                pq.pop();
            }
            res = max(res, sumS * e);
        }
        return res;
    }
};
