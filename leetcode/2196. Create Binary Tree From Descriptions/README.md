# [2196. Create Binary Tree From Descriptions (Medium)](https://leetcode.com/problems/create-binary-tree-from-descriptions/)

<p>You are given a 2D integer array <code>descriptions</code> where <code>descriptions[i] = [parent<sub>i</sub>, child<sub>i</sub>, isLeft<sub>i</sub>]</code> indicates that <code>parent<sub>i</sub></code> is the <strong>parent</strong> of <code>child<sub>i</sub></code> in a <strong>binary</strong> tree of <strong>unique</strong> values. Furthermore,</p>

<ul>
	<li>If <code>isLeft<sub>i</sub> == 1</code>, then <code>child<sub>i</sub></code> is the left child of <code>parent<sub>i</sub></code>.</li>
	<li>If <code>isLeft<sub>i</sub> == 0</code>, then <code>child<sub>i</sub></code> is the right child of <code>parent<sub>i</sub></code>.</li>
</ul>

<p>Construct the binary tree described by <code>descriptions</code> and return <em>its <strong>root</strong></em>.</p>

<p>The test cases will be generated such that the binary tree is <strong>valid</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/02/09/example1drawio.png" style="width: 300px; height: 236px;">
<pre><strong>Input:</strong> descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
<strong>Output:</strong> [50,20,80,15,17,19]
<strong>Explanation:</strong> The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/02/09/example2drawio.png" style="width: 131px; height: 300px;">
<pre><strong>Input:</strong> descriptions = [[1,2,1],[2,3,0],[3,4,1]]
<strong>Output:</strong> [1,2,null,null,3,4]
<strong>Explanation:</strong> The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= descriptions.length &lt;= 10<sup>4</sup></code></li>
	<li><code>descriptions[i].length == 3</code></li>
	<li><code>1 &lt;= parent<sub>i</sub>, child<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= isLeft<sub>i</sub> &lt;= 1</code></li>
	<li>The binary tree described by <code>descriptions</code> is valid.</li>
</ul>


**Similar Questions**:
* [Convert Sorted List to Binary Search Tree (Medium)](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)
* [Number Of Ways To Reconstruct A Tree (Hard)](https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/)

## Solution 1. Map

```cpp
// OJ: https://leetcode.com/problems/create-binary-tree-from-descriptions/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/create-binary-tree-from-descriptions/discuss/1823687/C%2B%2B-Map
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {  
        unordered_map<int, TreeNode*> getNode;
        unordered_map<int, bool> ischild;

        for (auto &node : des)
        {
            int curN = node[0], child = node[1], isleft = node[2];
            
            if (getNode.count(curN) == 0)
            {
                TreeNode* newN = new TreeNode(curN);
                getNode[curN] = newN;
            }
            if (getNode.count(child) == 0)
            {
                TreeNode* newN = new TreeNode(child);
                getNode[child] = newN;
            }
            ischild[child] = true;
            isleft == 1 ? getNode[curN]->left = getNode[child] : getNode[curN]->right = getNode[child];
        }
        
        
        TreeNode* ans;
        for (auto &node: des)
        {
            if (!ischild[node[0]])
            {
                ans = getNode[node[0]];
                break;
            }
        }
        
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/create-binary-tree-from-descriptions/discuss/1823606/
