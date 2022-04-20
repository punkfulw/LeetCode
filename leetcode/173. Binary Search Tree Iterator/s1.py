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
