from typing import Dict, List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        answer = []

        for i, key1 in enumerate(nums):
            for j, key2 in enumerate(nums[i+1:]):
                if (-(key1 + key2) in nums[i+j+2:]):
                    s = sorted([key1, key2, -(key1 + key2)])
                    if (s not in answer):
                        answer.append(s)
        return answer

_nums = [-1,0,1,2,-1,-4]

print(Solution().threeSum(_nums))