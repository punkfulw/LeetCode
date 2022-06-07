// OJ: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
    using vt = vector<int>;
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size(), target = times[targetFriend][0];
        priority_queue<int, vector<int>, greater<int>> pq_chair;
        priority_queue<vt, vector<vt>, greater<vt>> fri; 
        
        for (int i = 0; i <= 10000; i++)
            pq_chair.push(i);
        sort(times.begin(), times.end());
        for (auto t: times){
            while (!fri.empty() && t[0] >= fri.top()[0]){
                auto v = fri.top();
                fri.pop();
                pq_chair.push(v[1]);
            }
            if (t[0] == target)
                return pq_chair.top();
            fri.push({t[1], pq_chair.top()});
            pq_chair.pop();
        }
        return 0;
    }
};
