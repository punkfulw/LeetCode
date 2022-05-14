// OJ: https://leetcode.com/problems/network-delay-time/
// Author: github.com/punkfulw
// Time: O(E + VlogV)
// Space: O(E)
class Solution {
    typedef pair<int, int> pii;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans = INT_MAX;
        vector<vector<pii>> paths(n + 1);
        vector<int> costs(n + 1, INT_MAX);
        
        for (auto t: times)
            paths[t[0]].push_back({t[1], t[2]});
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, k});
        costs[k] = 0;
        while (!pq.empty()){
            auto [cnt, from] = pq.top();
            pq.pop();
            
            for (auto p: paths[from]){
                auto [to, cost] = p;
                if (cnt + cost < costs[to]){
                    costs[to] = cnt + cost;
                    pq.push({costs[to], to});
                } 
            }
        }
        ans = *max_element(costs.begin() + 1, costs.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
