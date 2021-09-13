# OJ: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        counter = {"b":0, "a":0, "l":0, "o":0, "n":0}
        for c in text:
            if c in counter:
                counter[c] += 1
        counter["l"] //= 2
        counter["o"] //= 2
        return min(counter.values())
