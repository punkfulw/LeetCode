# [1337. The K Weakest Rows in a Matrix (Easy)](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/)

<p>You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). 
  The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.</p>

<p>A row i is weaker than a row j if one of the following is true:</p>

<ul>
  <li>The number of soldiers in row i is less than the number of soldiers in row j.</li>
  <li>Both rows have the same number of soldiers and i < j.</li>
</ul>

<p>Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
<strong>Output:</strong> [2,0,3]
<strong>Explanation:</strong> 
The number of soldiers in each row is: 
- Row 0: 2 
- Row 1: 4 
- Row 2: 1 
- Row 3: 2 
- Row 4: 5 
The rows ordered from weakest to strongest are [2,0,3,1,4].
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
<strong>Output:</strong> [0,2]
<strong>Explanation:</strong> 
The number of soldiers in each row is: 
- Row 0: 1 
- Row 1: 4 
- Row 2: 1 
- Row 3: 1 
The rows ordered from weakest to strongest are [0,2,3,1].
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>m == mat.length</code></li>
  <li><code>n == mat[i].length</code></li>
  <li><code>2 &lt;= n, m &lt;= 100</code></li>
  <li><code>1 &lt;= k &lt;= m</code></li>
  <li>matrix[i][j] is either 0 or 1.</li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Matrix](https://leetcode.com/tag/matrix/)


## Solution 1. sort

```cpp
// OJ: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// Author: github.com/punkfulw
// Time: O(NMlogN)
// Space: O(N)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        vector<vector<int>> mp;
        for (int i = 0; i < mat.size(); i++){
            mp.push_back({i});
            mp[i].push_back(count(mat[i].begin(), mat[i].end(), 1));
        }
        sort(mp.begin(), mp.end(), [](vector<int> &a, vector<int> &b){
            if (a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        for (auto p: mp){
            ans.push_back(p[0]);
            if (ans.size() == k)
                break;
        }
        return ans;
    }
};
```

## Solution 2. set

```cpp
// OJ: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// Author: github.com/punkfulw
// Time: O(NMlogN)
// Space: O(N)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        set<pair<int, int>> mp;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++){
            int p = 0;
            while (p < m && mat[i][p] == 1)
                p++;
            mp.insert({p, i});
        }
        for (auto it = mp.begin(); k > 0; it++, k--)
            ans.push_back(it->second);
        return ans;
    }
};
```
