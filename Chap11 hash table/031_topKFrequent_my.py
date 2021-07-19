# Success
# Details 
# Runtime: 104 ms, faster than 55.18% of Python3 online submissions for Top K Frequent Elements.
# Memory Usage: 18.8 MB, less than 33.10% of Python3 online submissions for Top K Frequent Elements.

from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        dic = {}

        for i in nums:
            dic.setdefault(i, 0)
            dic[i] += 1

        dictolist = [(i, dic[i]) for i in dic]        
        dictolist = sorted(dictolist, key = lambda x : x[1], reverse= True)

        print(dictolist)

        return [i[0] for i in dictolist[0:k]]

_input = [1,1,1,2,2,3]
print(Solution().topKFrequent(_input, 2))