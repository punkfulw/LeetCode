# OJ: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(Q)
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        q = []
        if (root == None):
            return root
        q.append(root)
        while len(q):
            n = len(q)
            for i in range(n):
                cur = q[0]
                q.pop(0)

                if cur.left:
                    q.append(cur.left)
                if cur.right:
                    q.append(cur.right)
                if i == n - 1:
                    cur.next = None
                else:
                    cur.next = q[0]
        return root
