# [690. Employee Importance (Medium)](https://leetcode.com/problems/employee-importance/)

<p>You are given a data structure of employee information, which includes the employee's <b>unique id</b>, his <b>importance value</b> and his <b>direct</b> subordinates' id. </p>

<p>For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. They have importance value 15, 10 and 5, respectively. Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3 is also a subordinate of employee 1, the relationship is <b>not direct</b>.</p>

<p>Now given the employee information of a company, and an employee id, you need to return the total importance value of this employee and all his subordinates.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
<b>Output:</b> 11
<b>Explanation:</b>
Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3. They both have importance value 3. So the total importance value of employee 1 is 5 + 3 + 3 = 11.
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>One employee has at most one <b>direct</b> leader and may have several subordinates.</li>
<li>The maximum number of employees won't exceed 2000.</li>
</ol>
<p></p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Nested List Weight Sum (Easy)](https://leetcode.com/problems/nested-list-weight-sum/)

## Solution 1. DFS

```cpp
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
```

## Solution 2. BFS

```cpp
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
```
