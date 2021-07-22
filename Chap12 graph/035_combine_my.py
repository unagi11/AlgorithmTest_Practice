# Success
# Details 
# Runtime: 96 ms, faster than 84.97% of Python3 online submissions for Combinations.
# Memory Usage: 16.3 MB, less than 8.15% of Python3 online submissions for Combinations.

from typing import List

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:

        ansList = []
        
        def recurFunc(n, k, arr):
            # 사용가능한 수보다, 필요한 수의 개수가 많을수 없다.
            if n < k:
                return

            if k == 1:
                for i in range(1,n+1):
                    copyArr = arr[:]
                    copyArr.append(i)
                    ansList.append(copyArr)
            
            else:
                for i in range(1,n+1):
                    copyArr = arr[:]
                    copyArr.append(i)
                    recurFunc(i-1, k-1, copyArr)

        recurFunc(n, k, [])

        return ansList

print(Solution().combine(4,3))