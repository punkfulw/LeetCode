// OJ: https://leetcode.com/problems/employee-importance/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    unordered_map<int, Employee*> map;
    
    void sol(int &ans, vector<Employee*> &employees, int id){
        ans += map[id]->importance;
        for (auto sub: map[id]->subordinates)
            sol(ans, employees, sub);
    }
    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0;
        for (auto e: employees)
            map[e->id] = e;

        sol(ans, employees, id);
        return ans;
    }
};
