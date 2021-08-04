# Success
# Details 
# Runtime: 1184 ms, faster than 5.40% of Python3 online submissions for Largest Number.
# Memory Usage: 14.4 MB, less than 6.67% of Python3 online submissions for Largest Number.

from typing import List

class Solution:
    
    def listToNum(self, nums):

        number = ""

        for i in nums:
            number += str(i)
        
        return number
    
    def largestNumber(self, nums: List[int]) -> str:

        if not nums:
            return nums
        
        sortedNum = []
        maxnum = 0

        while nums:
            # print("sorted before", sortedNum)
            sortedNum = [nums.pop()] + sortedNum
            maxlist = sortedNum[:]
            # print("sorted after", sortedNum)

            for i in range(len(sortedNum)):                    
                if i != 0:
                    sortedNum[i-1], sortedNum[i] = sortedNum[i], sortedNum[i-1]

                # print("copy", sortedNum)

                copynum = int(self.listToNum(sortedNum))
                if maxnum < copynum:
                    # print(maxnum, "<", copynum)
                    maxlist = sortedNum[:]
                    maxnum = copynum

            sortedNum = maxlist
        
        answer = self.listToNum(sortedNum)

        if answer.count('0') == len(answer):
            return '0'
        else:
            return answer

nums = [10,2,9,39,17]
nums = [0,0]
print(Solution().largestNumber(nums))