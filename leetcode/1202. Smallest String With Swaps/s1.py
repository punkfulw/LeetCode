# OJ: https://leetcode.com/problems/smallest-string-with-swaps/
# Author: github.com/punkfulw
# Ref: https://leetcode.com/problems/smallest-string-with-swaps/discuss/388257/C%2B%2B-with-picture-union-find
# Time: O(NlogN)
# Space: O(N)
class Solution:
    def union_find(self, par, i):
        if (par[i] < 0):
            return i;
        par[i] = self.union_find(par, par[i])
        return par[i]
    
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        n = len(s)
        par = [-1 for _ in range(n)]
        arr = [[] for _ in range(n)]
        res = ['0' for _ in range(n)]
        
        for i, j in pairs:
            i = self.union_find(par, i)
            j = self.union_find(par, j)

            if i != j:
                par[j] = i
        
        for i in range(n):
            arr[self.union_find(par, i)].append(i) 
            
        for ids in arr:
            ss = ""
            for id in ids:
                ss += s[id]
            ss = sorted(ss)
            for i in range(len(ids)):
                res[ids[i]] = ss[i]
        return ''.join(res)
        
