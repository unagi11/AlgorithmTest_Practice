from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        _filtered = [(nums[i],i) for i in range(len(nums))]
        _filtered.sort(key = lambda x: x[0])
        
        print(_filtered)
        
        for i in range(len(_filtered)):
            for j in range(i +1 , len(_filtered)):
                if (_filtered[i][0] + _filtered[j][0] == target):
                    return [_filtered[i][1], _filtered[j][1]]
        
_nums = [-3,4,3,90]
_target = 0

_output = Solution().twoSum(_nums, _target)
print(_output)