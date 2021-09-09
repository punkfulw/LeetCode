# [919. Complete Binary Tree Inserter (Medium)](https://leetcode.com/problems/complete-binary-tree-inserter/)

<p>A <em>complete</em> binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.</p>

<p>Write a data structure&nbsp;<code>CBTInserter</code>&nbsp;that is initialized with a complete binary tree and supports the following operations:</p>

<ul>
	<li><code>CBTInserter(TreeNode root)</code> initializes the data structure on a given tree&nbsp;with head node <code>root</code>;</li>
	<li><code>CBTInserter.insert(int v)</code> will insert a <code>TreeNode</code>&nbsp;into the tree with value <code>node.val =&nbsp;v</code>&nbsp;so that the tree remains complete, <strong>and returns the value of the parent of the inserted <code>TreeNode</code></strong>;</li>
	<li><code>CBTInserter.get_root()</code> will return the head node of the tree.</li>
</ul>

<ol>
</ol>

<div>
<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>inputs = <span id="example-input-1-1">["CBTInserter","insert","get_root"]</span>, inputs = <span id="example-input-1-2">[[[1]],[2],[]]</span>
<strong>Output: </strong><span id="example-output-1">[null,1,[1,2]]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>inputs = <span id="example-input-2-1">["CBTInserter","insert","insert","get_root"]</span>, inputs = <span id="example-input-2-2">[[[1,2,3,4,5,6]],[7],[8],[]]</span>
<strong>Output: </strong><span id="example-output-2">[null,3,4,[1,2,3,4,5,6,7,8]]</span></pre>
</div>

<div>
<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li>The initial given tree is complete and contains between <code>1</code> and <code>1000</code> nodes.</li>
	<li><code>CBTInserter.insert</code> is called at most <code>10000</code> times per test case.</li>
	<li>Every value of a given or inserted node is between <code>0</code> and <code>5000</code>.</li>
</ol>
</div>
</div>

<div>
<p>&nbsp;</p>

<div>&nbsp;</div>
</div>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/complete-binary-tree-inserter/
// Author: github.com/punkfulw
// Time:
//     CBTInserter: O(1)
//     insert: O(N)
//     get_root: O(1)
// Space: O(N)
class CBTInserter {
public:
    TreeNode* r;
    CBTInserter(TreeNode* root) {
        r = root;
    }
    int insert(int val) {
        TreeNode* node = new TreeNode(val);
        queue<TreeNode*> q;
        q.push(r);
        while (true){
            int n = q.size();
            for (int i = 0; i < n; i++){
                auto cur = q.front(); q.pop();
                if (cur->left == NULL){
                    cur->left = node;
                    return cur->val;
                }
                if (cur->right == NULL){
                    cur->right = node;
                    return cur->val;
                }
                q.push(cur->left);
                q.push(cur->right);
            }
        }
    }
    TreeNode* get_root() {
        return r;
    }
};
```

## Solution 2. array

```cpp
// OJ: https://leetcode.com/problems/complete-binary-tree-inserter/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/complete-binary-tree-inserter/discuss/178424/C%2B%2BJavaPython-O(1)-Insert
// Time:
//     CBTInserter: O(N)
//     insert: O(1)
//     get_root: O(1)
// Space: O(N)
class CBTInserter {
public:
    vector<TreeNode*> tree;
    CBTInserter(TreeNode* root) {
        tree.push_back(root);
        for (int i = 0; i < tree.size(); i++){
            if (tree[i]->left) tree.push_back(tree[i]->left);
            if (tree[i]->right) tree.push_back(tree[i]->right);
        }
    }
    
    int insert(int val) {
        int n = tree.size();
        TreeNode* node = new TreeNode(val);
        tree.push_back(node);
        if (n % 2)
            tree[n / 2]->left = node;
        else
            tree[(n - 1) / 2]->right = node;
        return tree[(n - 1) / 2]->val;
    }
    
    TreeNode* get_root() {
        return tree[0];
    }
};
```
