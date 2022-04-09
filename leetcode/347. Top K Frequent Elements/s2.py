# OJ: https://leetcode.com/problems/top-k-frequent-elements/
# Author: github.com/punkfulw
# Time: O(N) 
# Space: O(U)
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnt = Counter(nums).items()  
        buckets = [[] for _ in range(len(nums) + 1)]
        for num, freq in cnt:
            buckets[freq].append(num)
        
        ans = []
        for i in range(len(buckets) - 1, -1, -1):
            if len(buckets[i]):
                for num in buckets[i]:
                    ans.append(num)
        return ans[:k]
