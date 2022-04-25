# OJ: https://leetcode.com/problems/peeking-iterator/
# Author: github.com/punkfulw
# Ref: https://leetcode.com/problems/peeking-iterator/discuss/1055977/Python-3-Greedy-and-lazy-24ms
# Time: O(1)
# Space: O(1) 
class PeekingIterator:
    def __init__(self, iterator):
        self._iter = iterator
        self.val = None
        self.hasnext = False
        self.next()
        
    def peek(self):
        return self.val

    def next(self):
        cur = self.val
        self.hasnext = self._iter.hasNext()
        if self.hasnext:
            self.val = self._iter.next()
        return cur

    def hasNext(self):
        return self.hasnext
