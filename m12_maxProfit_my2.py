from typing import List

# 실패!

class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        left = 0
        right = len(prices) - 1
        left_min = prices[left]
        right_max = prices[right]
        _profit = right_max - left_min
        max = _profit

        while left < right:

            print("l", left, left_min, "r", right, right_max)

            
            if prices[left] > prices[left + 1]:
                left += 1
                left_min = prices[left]
                _profit = right_max - left_min
                if _profit > max:
                    max = _profit

                continue
            if prices[right] < prices[right - 1]:
                right -= 1
                right_max = prices[right]
                _profit = right_max - left_min
                if _profit > max:
                    max = _profit

                continue

            # 왼쪽의 상승폭과 오른쪽의 하락폭중에 더 적은 쪽으로 이동한다.
            if prices[right] - prices[right-1] < prices[left+1] - prices[left]:
                right -= 1
            elif prices[right] - prices[right-1] > prices[left+1] - prices[left]:
                left += 1
            else :
                right -= 1
                left += 1

        return max


_input = [7,6,4,3,1]
#_input = [7,1,5,3,6,4]
#_input = [7,6,4,3,1]
#_input = [1,2]
print(Solution().maxProfit(_input))