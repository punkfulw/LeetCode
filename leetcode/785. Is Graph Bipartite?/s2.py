# OJ: https://leetcode.com/problems/is-graph-bipartite/
# Author: github.com/punkfulw
# Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/785.%20Is%20Graph%20Bipartite%3F/README.md
# Time: O(V + E)
# Space: O(V + E)
class Solution:
    def dfs(self, G, i, prev):
        if self.id[i]:
            return self.id[i] != prev
        self.id[i] = -prev
        for child in G[i]:
            if not self.dfs(G, child, -prev):
                return False
        return True
    
    def isBipartite(self, G: List[List[int]]) -> bool:
        n = len(G)
        self.id = [0 for _ in range(n)]
        for i in range(n):
            if not self.id[i] and not self.dfs(G, i, 1):
                return False
        return True
