# [429. N-ary Tree Level Order Traversal (Easy)](https://leetcode.com/problems/n-ary-tree-level-order-traversal/)

<p>Given an n-ary tree, return the <em>level order</em>. traversal of its nodes' values.</p>

<p><em>Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).</em></p>


<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> root = [1,null,3,2,4,null,5,6]
<strong>Output:</strong> [[1],[3,2,4],[5,6]]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" style="width: 200px; height: 50px;">
<pre>
<strong>Input:</strong> [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>Output:</strong> [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The height of the n-ary tree is less than or equal to <code>1000</code></li>
  <li>The total number of nodes is between <code>[0, 10<sup>4</sup>]</code></li>
</ul>



**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [BFS](https://leetcode.com/tag/breadth-first-search/)


## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        bfs(root, ans, 0);
        return ans;
    }
    void bfs(Node* root, vector<vector<int>>& ans, int level) {
        if (root != NULL){
            if (ans.size() < level + 1)
                ans.push_back({});
            ans[level].push_back(root->val);
            for (auto child: root->children)
                bfs(child, ans, level+1);
        }
    }
};
```

## Solution 2. QUEUE

```cpp
// OJ: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/429.%20N-ary%20Tree%20Level%20Order%20Traversal/README.md
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while (q.size()) {
            int cnt = q.size();
            vector<int> level;
            while (cnt--) {
                root = q.front();
                q.pop();
                level.push_back(root->val);
                for (Node *node : root->children) q.push(node);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
```
