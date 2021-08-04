# Success
# Details 
# Runtime: 68 ms, faster than 54.35% of Python3 online submissions for Kth Largest Element in an Array.
# Memory Usage: 15.2 MB, less than 22.05% of Python3 online submissions for Kth Largest Element in an Array.

from typing import List

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.sort()
        print(nums)

        return nums[-k]
        
nums = [3,2,1,5,6,4]
k = 2
print(Solution().findKthLargest(nums, k))