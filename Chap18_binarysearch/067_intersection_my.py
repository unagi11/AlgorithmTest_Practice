# Success
# Details 
# Runtime: 40 ms, faster than 92.38% of Python3 online submissions for Intersection of Two Arrays.
# Memory Usage: 14.5 MB, less than 47.19% of Python3 online submissions for Intersection of Two Arrays.

from typing import List

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:

        set1 = set(nums1)
        set2 = set(nums2)

        answer = []

        for i in set1:
            if i in set2:
                answer.append(i)

        return answer

nums1 = [1,2,2,1]
nums2 = [2,2]

print(Solution().intersection(nums1, nums2))