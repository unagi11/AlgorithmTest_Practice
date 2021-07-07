from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        mul = 1
        right = []
        for val in nums:
            mul *= val
            right.append(mul)

        mul = 1
        left = []
        for val in nums[::-1]:
            mul *= val
            left.append(mul)

        result = []

        for i, val in enumerate(nums):
            r = 1
            l = 1
            if i != 0:
                r = right[i-1]
            if i != len(nums)-1:
                l = left[len(nums)-2-i]
            
            result.append(r * l)
        return result

#_input = [1,2,3,4]
_input = [-1,1,0,-3,3]
print(Solution().productExceptSelf(_input))