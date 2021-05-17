// OJ: https://leetcode.com/problems/number-of-recent-calls/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class RecentCounter {
public:
    RecentCounter() {
    }
    queue<int> q;
    int ping(int t) {
        q.push(t);
        while (q.front() < t-3000)
            q.pop();
        return q.size();
    }
};
