# [427. Construct Quad Tree (Medium)](https://leetcode.com/problems/construct-quad-tree/)

<p>Given a <code>n * n</code> matrix <code>grid</code> of <code>0's</code> and <code>1's</code> only. We want to represent the <code>grid</code> with a Quad-Tree.</p>

<p>Return <em>the root of the Quad-Tree</em> representing the <code>grid</code>.</p>

<p>Notice that you can assign the value of a node to <strong>True</strong> or <strong>False</strong> when <code>isLeaf</code> is <strong>False</strong>, and both are <strong>accepted</strong> in the answer.</p>

<p>A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:</p>

<ul>
	<li><code>val</code>: True if the node represents a grid of 1's or False if the node represents a grid of 0's.&nbsp;</li>
	<li><code>isLeaf</code>: True if the node is leaf node on the tree or False if the node has the four children.</li>
</ul>

<pre>class Node {
    public boolean val;
&nbsp; &nbsp; public boolean isLeaf;
&nbsp; &nbsp; public Node topLeft;
&nbsp; &nbsp; public Node topRight;
&nbsp; &nbsp; public Node bottomLeft;
&nbsp; &nbsp; public Node bottomRight;
}</pre>

<p>We can construct a Quad-Tree from a two-dimensional area using the following steps:</p>

<ol>
	<li>If the current grid has the same value (i.e all <code>1's</code> or all <code>0's</code>)&nbsp;set <code>isLeaf</code>&nbsp;True and set <code>val</code> to the value of the grid and set the four children to Null and stop.</li>
	<li>If the current grid has different values, set <code>isLeaf</code> to False and&nbsp;set <code>val</code> to any value and divide the current grid into four sub-grids as shown in the photo.</li>
	<li>Recurse for each of the children with the proper sub-grid.</li>
</ol>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/11/new_top.png" style="width: 777px; height: 181px;">
<p>If you want to know more about the Quad-Tree, you can refer to the&nbsp;<a href="https://en.wikipedia.org/wiki/Quadtree">wiki</a>.</p>

<p><strong>Quad-Tree&nbsp;format:</strong></p>

<p>The output represents the serialized format of a Quad-Tree using level order traversal, where <code>null</code> signifies a path terminator where no node exists below.</p>

<p>It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list <code>[isLeaf, val]</code>.</p>

<p>If the value of <code>isLeaf</code> or <code>val</code> is True we represent it as <strong>1</strong> in the list&nbsp;<code>[isLeaf, val]</code> and if the value of <code>isLeaf</code> or <code>val</code> is False we represent it as <strong>0</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/11/grid1.png" style="width: 777px; height: 99px;">
<pre><strong>Input:</strong> grid = [[0,1],[1,0]]
<strong>Output:</strong> [[0,1],[1,0],[1,1],[1,1],[1,0]]
<strong>Explanation:</strong> The explanation of this example is shown below:
Notice that 0 represnts False and 1 represents True in the photo representing the Quad-Tree.
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/12/e1tree.png" style="width: 777px; height: 186px;">
</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/02/12/e2mat.png" style="width: 777px; height: 343px;"></p>

<pre><strong>Input:</strong> grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
<strong>Output:</strong> [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
<strong>Explanation:</strong> All values in the grid are not the same. We divide the grid into four sub-grids.
The topLeft, bottomLeft and bottomRight each has the same value.
The topRight have different values so we divide it into 4 sub-grids where each has the same value.
Explanation is shown in the photo below:
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/12/e2tree.png" style="width: 777px; height: 328px;">
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1],[1,1]]
<strong>Output:</strong> [[1,1]]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> grid = [[0]]
<strong>Output:</strong> [[1,0]]
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]]
<strong>Output:</strong> [[0,1],[1,1],[1,0],[1,0],[1,1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>n == 2^x</code> where <code>0 &lt;= x &lt;= 6</code></li>
</ul>


**Companies**:  
[Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Tree](https://leetcode.com/tag/tree/), [Matrix](https://leetcode.com/tag/matrix/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/construct-quad-tree/
// Author: github.com/punkfulw
// Time: O(log_4^N * N^2)
// Space: O(log_4^N)
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int same = 1, val = grid[0][0], n = grid.size();
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] != val)
                    same = 0;
        Node* node = new Node();
        if (same){
            node->isLeaf = true;
            node->val = val;
        }
        else {
            vector<vector<int>> tl(n / 2), tr(n / 2), bl(n / 2), br(n / 2);
            
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++){
                    if (i < n / 2 && j < n / 2)
                        tl[i].push_back(grid[i][j]);
                    else if (i < n / 2 && j >= n / 2)
                        tr[i].push_back(grid[i][j]);
                    else if (i >= n / 2 && j < n / 2)
                        bl[i - n / 2].push_back(grid[i][j]);
                    else if (i >= n / 2 && j >= n / 2)
                        br[i - n / 2].push_back(grid[i][j]);
                }
            
            node->topLeft = construct(tl);
            node->topRight = construct(tr);
            node->bottomLeft = construct(bl);
            node->bottomRight = construct(br);
            node->isLeaf = false;
        }
        return node;
            
    }
};
```

## Solution 2. Prefix Sum

```cpp
// OJ: https://leetcode.com/problems/construct-quad-tree/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/427.%20Construct%20Quad%20Tree/README.md
// Time: O(N^2 + log_4^N * N)
// Space: O(N^2)
class Solution {
public:
    vector<vector<int>> prefix;
    
    Node* dfs(int x, int y, int N){
        int sum = prefix[x + N][y + N] - prefix[x][y + N] - prefix[x + N][y] + prefix[x][y];
        if (sum == N * N || sum == 0)
            return new Node(sum, 1);
        return new Node(true, false,
                        dfs(x, y, N / 2),
                        dfs(x, y + N / 2, N / 2),
                        dfs(x + N / 2, y, N / 2),
                        dfs(x + N / 2, y + N / 2, N / 2));
    }
    
    Node* construct(vector<vector<int>>& nums) {
        int n = nums.size();    
        prefix.resize(n + 1, vector<int> (n + 1));
        for (int i = 1; i <= n; i++){
            int sum = 0;
            for (int j = 1; j <= n; j++){
                sum += nums[i - 1][j - 1];
                prefix[i][j] = sum + prefix[i - 1][j];
            }
        }
        
        return dfs(0, 0, n);
        
    }
};
```
