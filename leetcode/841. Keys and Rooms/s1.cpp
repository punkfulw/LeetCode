// OJ: https://leetcode.com/problems/keys-and-rooms/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(N) 
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> vis;
        queue<int> q;
        
        vis.insert(0);
        q.push(0);
        
        while (!q.empty()){
            auto room = q.front();
            q.pop();
            for (auto &nxt: rooms[room]){
                if (vis.find(nxt) == vis.end()){
                    q.push(nxt);
                    vis.insert(nxt);
                }
            }
        }
        return vis.size() == n;
    }
};
