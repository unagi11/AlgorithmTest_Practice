# Success
# Details 
# Runtime: 672 ms, faster than 69.83% of Python3 online submissions for K Closest Points to Origin.
# Memory Usage: 19.8 MB, less than 66.40% of Python3 online submissions for K Closest Points to Origin.

from typing import List

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:

        calculated = [(i[0]**2 + i[1]**2, i) for i in points]

        calculated.sort()

        answer = [calculated[index][1] for index in range(k)]

        return answer


points = [[3, 3], [5, -1], [-2, 4], [1, 1], [-1, 2]]
points = [[1, 3], [-2, 2]]
k = 2

print(Solution().kClosest(points, k))
