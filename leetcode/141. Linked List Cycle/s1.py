# OJ: https://leetcode.com/problems/linked-list-cycle/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        fast = slow = head
        while fast and slow:
            slow = slow.next
            if fast.next:
                fast = fast.next.next
            else:
                fast = fast.next
            if slow and fast and slow == fast:
                return True
        return False
