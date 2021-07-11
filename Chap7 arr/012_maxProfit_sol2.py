
# 그냥 원 포인터로 풀리는 문제였다.

from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        profit = 0
        import sys
        min_price = sys.maxsize

        for price in prices:
            # 현재 시점의 저점과 이익을 비교, 기록한다.
            min_price = min(min_price, price)
            profit = max(profit, price - min_price)
            
        return profit

_input = [7,6,4,3,1]
print(Solution().maxProfit(_input))