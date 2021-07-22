# Success
# Details 
# Runtime: 56 ms, faster than 87.49% of Python3 online submissions for Combination Sum.
# Memory Usage: 14.5 MB, less than 24.07% of Python3 online submissions for Combination Sum.

from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:

        candidates = sorted(candidates)

        ans = []

        def recurFunc(arr: List[int], candidates: List[int], target: int):
            
            for i, v in enumerate(candidates):
                newarr = arr[:]
                newarr.append(v)
                _sum = sum(newarr)

                if _sum == target:
                    ans.append(newarr)
                    return
                elif _sum > target:
                    return
                else :
                    recurFunc(newarr, candidates[i:], target)

        recurFunc([], candidates, target)

        return ans


print(Solution().combinationSum([2,7,6,3,5,1],9))
