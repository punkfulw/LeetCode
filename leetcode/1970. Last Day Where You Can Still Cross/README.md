# [1970. Last Day Where You Can Still Cross (Hard)](https://leetcode.com/problems/last-day-where-you-can-still-cross/submissions/)

<p>There is a <b>1-based</b> binary matrix where <code>0</code> represents land and <code>1</code> represents water. 
  You are given integers row and col representing the number of rows and columns in the matrix, respectively.</p>

<p>Initially on day <code>0</code>, the <b>entire</b> matrix is <b>land</b>. However, each day a new cell becomes flooded with <b>water</b>. 
  You are given a <b>1-based</b> 2D array <code>cells</code>, where <code>cells[i] = [ri, ci]</code> represents that on the <code>i<sup>th</sup></code> day, 
  the cell on the <code>r<sub>i</sub><sup>th</sup></code> row and <code>c<sub>i</sub><sup>th</sup></code> column (<b>1-based</b> coordinates) will be covered with <b>water</b> (i.e., changed to 1).</p>

<p>You want to find the <b>last</b> day that it is possible to walk from the <b>top</b> to the <b>bottom</b> by only walking on land cells. 
  You can start from <b>any</b> cell in the top row and end at <b>any</b> cell in the bottom row. 
  You can only travel in the four cardinal directions (left, right, up, and down).</p>

<p>Return <em>the <b>last</b> day where it is possible to walk from the <b>top</b> to the <b>bottom</b> by only walking on land cells.</em></p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/27/1.png" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/27/2.png" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.
</pre>


<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/27/3.png" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>2 &lt;= row, col &lt;= 2 * 10<sup>4</sup></code></li>
  <li><code>4 &lt;= row * col &lt;= 2 * 10<sup>4</sup></code></li>
  <li><code>cells.length == row * col</code></li>
  <li><code>1 &lt;= ri &lt;= row</code></li>
  <li><code>1 &lt;= ci &lt;= col</code></li>
  <li>All the values of <code>cells</code> are <b>unique</b>.</li>
</ul>





## Solution 1. DFS + Binary search
``
come up with the dfs + linear search and got TLE in the contest
``
```cpp
// OJ: https://leetcode.com/problems/last-day-where-you-can-still-cross/submissions/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/last-day-where-you-can-still-cross/discuss/1404042/C%2B%2B-Binary-Search-and-DFS
// Time: O(N^2 * logN*N)
// Space: O(N)
class Solution {
public:
    vector<int> x = {0, 1, -1, 0};
    vector<int> y = {1, 0, 0, -1};
    
    bool check(vector<vector<int>> &A, int i, int j){
        return (i >= 0 && j >= 0 && i < A.size() && j < A[0].size() && A[i][j] == 0);
    }
    
    bool dfs(vector<vector<int>> &A, int i, int j){
        if (i == A.size()-1)
            return true;
        
        A[i][j] = 1;
        
        for(int k = 0; k < 4; k++){
            int u = i + x[k];
            int v = j + y[k];
            
            if (check(A,u,v))
                if (dfs(A,u,v))
                    return true;
        }
        return false;
    }
    
    bool check(vector<vector<int>> &A, int mid){
        if (mid < A[0].size())       //There will always be way to reach bottom in this case
            return true;            //Worst case : all boxes in 1st row gets filled one by one.
        
        for (int i = 0; i < A[0].size(); i++)
            if (A[0][i] == 0 )
                if (dfs(A, 0, i))
                    return true;
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& B) {
        
        int start = 0;
        int end = B.size() - 1;
                             
        while (start <= end){
            
            int mid = start + (end-start)/2;
            
            vector<vector<int>> A(row, vector<int> (col, 0));
            
            for (int i = 0;i < mid; i++){
                int u = B[i][0] - 1;
                int v = B[i][1] - 1;
                A[u][v] = 1;
            }
            
            if (check(A, mid))
                start = mid + 1;
            else
                end = mid - 1;
        
        }
        return end;
    }
};
```
