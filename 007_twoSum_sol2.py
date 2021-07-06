from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i, num in enumerate(nums):
            print(i,num)
            if (target - num in nums[i+1:]):
                return [i,nums[i+1:].index(target - num)+i+1]

        # for index in range(len(nums)):
        #     if (target - nums[index] in nums[index+1:]):
        #         return [index, index+1+nums[index+1:].index(target-nums[index])]
        
_nums = [3,2,4]
_target = 6

_output = Solution().twoSum(_nums, _target)
print(_output)