# Success
# Details 
# Runtime: 32 ms, faster than 75.46% of Python3 online submissions for Sort Colors.
# Memory Usage: 14.2 MB, less than 75.69% of Python3 online submissions for Sort Colors.

# 답 보고 풀었다 이말이야

from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0
        j = 0
        k = len(nums)

        while j < k:
            if nums[j] < 1:
                nums[i], nums[j] = nums[j], nums[i]
                i = i + 1
                j = j + 1
            elif nums[j] > 1:
                k = k - 1
                nums[j], nums[k] = nums[k], nums[j]
            else:
                j = j + 1

        return nums


print(Solution().sortColors([0,1,2,0,2,1,2]))