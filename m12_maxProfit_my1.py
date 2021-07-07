from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        delta = []
        for i, val in enumerate(prices[:len(prices)-1]):
            delta.append(prices[i+1] - prices[i])

        max = 0

        for i in range(len(delta)):
            for j in range(i,len(delta)+1):
                if (max < sum(delta[i:j])):
                    max = sum(delta[i:j])

        return max
start = []
#_input = [7,1,5,3,6,4]
#_input = [7,6,4,3,1]
_input = [1,2]
print(Solution().maxProfit(_input))