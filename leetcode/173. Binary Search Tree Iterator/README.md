# [173. Binary Search Tree Iterator (Medium)](https://leetcode.com/problems/binary-search-tree-iterator/)

<p>Implement the <code>BSTIterator</code> class that represents an iterator over the <b>in-order traversal</b> of a binary search tree (BST):</p>

<ul>
	<li><code>BSTIterator(TreeNode root)</code> Initializes an object of the <code>BSTIterator</code> class. The <code>root</code> of the BST is given as part of the constructor. 
    The pointer should be initialized to a non-existent number smaller than any element in the BST.</li>
	<li><code>boolean hasNext()</code> Returns <code>true</code> if there exists a number in the traversal to the right of the pointer, otherwise returns <code>false</code>.</li>
  <li><code>int next()</code> Moves the pointer to the right, then returns the number at the pointer.</li>
</ul>

<p>Notice that by initializing the pointer to a non-existent smallest number, the first call to <code>next()</code>  will return the smallest element in the BST.</p>

<p>You may assume that <code>next()</code> calls will always be valid. That is, there will be at least a next number in the in-order traversal when <code>next()</code> is called.</p>
<p>&nbsp;</p>

<ul>
</ul>


<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/25/bst-tree.png" style="width: 189px; height: 178px;">
<pre>
<strong>Input:</strong> ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
<strong>Output:</strong> 
[null, 3, 7, true, 9, true, 15, true, 20, false]
<strong>Explanation:</strong> 
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
</pre>

<p>&nbsp;</p>

<p><b>Constraints:</b></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
  <li><code>0 &lt;= Node.val &lt;= 10<sup>6</sup></code></li>
  <li>At most <code>10<sup>5</sup></code> calls will be made to <code>hasNext</code>, and <code>next</code>.</li>
</ul>



**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Oracle](https://leetcode.com/company/oracle), [Bloomberg](https://leetcode.com/company/bloomberg), [Qualtrics](https://leetcode.com/company/qualtrics), [Cloudera](https://leetcode.com/company/cloudera), [Uber](https://leetcode.com/company/uber), [Google](https://leetcode.com/company/google), [LinkedIn](https://leetcode.com/company/linkedin), [Cisco](https://leetcode.com/company/cisco)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Binary Tree Inorder Traversal (Medium)](https://leetcode.com/problems/binary-tree-inorder-traversal/)
* [Flatten 2D Vector (Medium)](https://leetcode.com/problems/flatten-2d-vector/)
* [Zigzag Iterator (Medium)](https://leetcode.com/problems/zigzag-iterator/)
* [Peeking Iterator (Medium)](https://leetcode.com/problems/peeking-iterator/)
* [Inorder Successor in BST (Medium)](https://leetcode.com/problems/inorder-successor-in-bst/)

## Solution 1. Stack

```cpp
// OJ: https://leetcode.com/problems/binary-search-tree-iterator/
// Author: github.com/punkfulw
// Time: O(1) 
// Space: O(H)
class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        auto cur = stk.top();
        stk.pop();
        pushAll(cur->right);
        return cur->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
    void pushAll(TreeNode* root){
        while (root){
            stk.push(root);
            root = root->left;
        }
        return;
    }
};
```

## Solution 1. -py

```python3
# OJ: https://leetcode.com/problems/binary-search-tree-iterator/
# Author: github.com/punkfulw
# Time: O(1) 
# Space: O(H)
class BSTIterator:
    stk = []
    def __init__(self, root: Optional[TreeNode]):
        self.pushAll(root)

    def next(self) -> int:
        cur = self.stk.pop()
        self.pushAll(cur.right)
        return cur.val

    def hasNext(self) -> bool:
        return len(self.stk) != 0
    
    def pushAll(self, root) -> None:
        while root:
            self.stk.append(root)
            root = root.left

```


