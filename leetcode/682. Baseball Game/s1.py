# OJ: https://leetcode.com/problems/baseball-game/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(N)
class Solution:
    def calPoints(self, ops: List[str]) -> int:
        ans = []
        idx = -1
        for op in ops:
            if op == "C":
                ans.pop()
                idx -= 1
            elif op == "D":
                ans.append(ans[idx] * 2)
                idx += 1
            elif op == "+":
                ans.append(ans[idx] + ans[idx - 1])
                idx += 1
            else :
                ans.append(int(op))
                idx += 1
        return sum(ans)
