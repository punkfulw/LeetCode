// OJ: https://leetcode.com/problems/last-stone-weight/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int> q(begin(stones), end(stones));
      while (q.size() > 1) {
        auto w1 = q.top(); q.pop();
        auto w2 = q.top(); q.pop();
        if (w1 - w2 > 0) q.push(w1 - w2);
      }
      return q.empty() ? 0 : q.top();
    }
};
