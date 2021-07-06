from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for index in range(len(nums)):
            if (target - nums[index] in nums[index+1:]):
                return [index, index+1+nums[index+1:].index(target-nums[index])]
        
_nums = [-3,4,3,90]
_target = 0

_output = Solution().twoSum(_nums, _target)
print(_output)