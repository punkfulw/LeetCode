// OJ: https://leetcode.com/problems/employee-importance/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    unordered_map<int, Employee*> map;
    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0;
        queue<int> q;
        q.push(id);
        
        for (auto e: employees)
            map[e->id] = e; 
        
        while (!q.empty()){
            auto e = q.front();
            q.pop();
            ans += map[e]->importance;
            for (auto sub: map[e]->subordinates)
                q.push(sub);
        }
        return ans;
    }
};
