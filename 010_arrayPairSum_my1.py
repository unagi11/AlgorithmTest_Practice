from typing import List

class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        result = 0
        for i in range(0, len(nums), 2):
            result += nums[i]

        return result

_input = [6,2,6,5,1,2]
print(Solution().arrayPairSum(_input))