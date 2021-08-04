# Success
# Details 
# Runtime: 56 ms, faster than 96.28% of Python3 online submissions for Kth Largest Element in an Array.
# Memory Usage: 15.2 MB, less than 46.31% of Python3 online submissions for Kth Largest Element in an Array.

from typing import List
import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        return heapq.nlargest(k, nums)[-1]
        
nums = [3,2,1,5,6,4]
k = 2
print(Solution().findKthLargest(nums, k))