# Success
# Details 
# Runtime: 3920 ms, faster than 5.00% of Python3 online submissions for Two Sum II - Input array is sorted.
# Memory Usage: 14.4 MB, less than 96.74% of Python3 online submissions for Two Sum II - Input array is sorted.from typing import List

# Success
# Details 
# Runtime: 2948 ms, faster than 5.00% of Python3 online submissions for Two Sum II - Input array is sorted.
# Memory Usage: 14.7 MB, less than 33.60% of Python3 online submissions for Two Sum II - Input array is sorted.

from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for key, val in enumerate(numbers):
            copyed = numbers[key + 1:]
            if target - val in copyed:
                return [key + 1, key + copyed.index(target - val) + 2]
        return None

numbers = [-1,0]
target = -1
print(Solution().twoSum(numbers, target))
