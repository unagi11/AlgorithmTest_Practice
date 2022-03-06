from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:

        ans = []

        # 부분집합의 개수
        for i in range(2**len(nums)):
            # print(i)
            temp = []
            numlist = []

            for j in range(len(nums)-1,-1,-1):
                temp.append((i>>j)%2==1)
            # print(temp)
            for j in range(len(nums)):
                if (temp[j] == True):
                    numlist.append(nums[j])
            
            ans.append(numlist)

        return ans

print(Solution().subsets([0]))