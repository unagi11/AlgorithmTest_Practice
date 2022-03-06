# Success
# Details 
# Runtime: 44 ms, faster than 47.09% of Python3 online submissions for Search in Rotated Sorted Array.
# Memory Usage: 15 MB, less than 23.61% of Python3 online submissions for Search in Rotated Sorted Array.

from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        length = len(nums)
        start = nums.index(min(nums))

        keyval = []

        for key, val in enumerate(nums):
            keyval.append((key,val))

        복구_리스트 = []

        for i in range(length):
            복구_리스트.append(keyval[(start + i) % length])

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

        return recursive(복구_리스트, target)

nums = [5,6,7,0,1,2]
target = 0

print(Solution().search(nums, target))