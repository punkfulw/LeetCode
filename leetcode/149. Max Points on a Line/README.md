# [149. Max Points on a Line (Hard)](https://leetcode.com/problems/max-points-on-a-line/)

Given _n_ points on a 2D plane, find the maximum number of points that lie on the same straight line.

**Example 1:**

**Input:** \[\[1,1\],\[2,2\],\[3,3\]\]  
**Output:** 3  
**Explanation:**
```
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
```

**Example 2:**

**Input:** \[\[1,1\],\[3,2\],\[5,3\],\[4,1\],\[2,3\],\[1,4\]\]  
**Output:** 4  
**Explanation:**
```
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
```

## Solution 1. 


```cpp
// OJ: https://leetcode.com/problems/max-points-on-a-line/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ver[20002] = {}, hor[20002] = {}, shift = 1e4, n = points.size(), ans = 1;
        set<pair<double, int>> vis;
        
        for (int i = 0; i < n; i++){
            unordered_map<double, int> mp;
            int x = points[i][0], y = points[i][1];
            ver[y + shift]++;
            hor[x + shift]++;
            ans = max({ans, ver[y + shift], hor[x + shift]});
            for (int j = i + 1; j < n; j++){
                int r = points[j][0], c = points[j][1];
                if (r == x || c == y)
                    continue;
                double slope = double(c - y) / (r - x);

                if (vis.find({slope, j}) != vis.end())
                    continue;
                mp[slope]++;
                vis.insert({slope, j});
                ans = max(ans, mp[slope] + 1);
            }
        }
        return ans;
    }
};
```
