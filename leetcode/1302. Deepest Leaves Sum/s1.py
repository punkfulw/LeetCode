# OJ: https://leetcode.com/problems/deepest-leaves-sum/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(H)
class Solution:
    def dfs(self, root, level):
        if root == None:
            return 
        if not root.left and not root.right and level >= self.ans[0]:
            if level == self.ans[0]:
                self.ans[1] += root.val
            else:
                self.ans = [level, root.val]
        self.dfs(root.left, level + 1)        
        self.dfs(root.right, level + 1)
        
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        self.ans = [0, 0]
        self.dfs(root, 0)
        
        return self.ans[1]
