// OJ: https://leetcode.com/problems/slowest-key/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution:
    def slowestKey(self, re: List[int], keys: str) -> str:
        ans, dur = keys[0], re[0]
        
        for i in range(1, len(re)):
            time = re[i] - re[i-1]
            if time > dur or (time == dur and keys[i] > ans):
                ans = keys[i]
                dur = re[i] - re[i-1]
        return ans
