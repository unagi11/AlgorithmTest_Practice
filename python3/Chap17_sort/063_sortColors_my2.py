# Success
# Details 
# Runtime: 36 ms, faster than 48.44% of Python3 online submissions for Sort Colors.
# Memory Usage: 14.2 MB, less than 75.69% of Python3 online submissions for Sort Colors.

from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.sort()

        return nums


print(Solution().sortColors([0,1,2,0,2,1,2]))