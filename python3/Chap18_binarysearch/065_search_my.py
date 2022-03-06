# Success
# Details 
# Runtime: 260 ms, faster than 16.81% of Python3 online submissions for Binary Search.
# Memory Usage: 15.8 MB, less than 30.60% of Python3 online submissions for Binary Search.

from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:

        keyval = []

        for key, val in enumerate(nums):
            keyval.append((key,val))

        def recursive(nums, target):
            if not nums or (len(nums) == 1 and nums[0][1] != target):
                return -1

            midindex = len(nums) // 2
            midval = nums[midindex]

            if midval[1] == target:
                return midval[0]
            elif midval[1] < target:
                return recursive(nums[midindex:], target)
            else:
                return recursive(nums[:midindex], target)

        return recursive(keyval, target)

# nums = [-1,0,3,5,9,12]
# target = 9
nums = [-1,0,3,5,9,12]
target = 2

print(Solution().search(nums, target))