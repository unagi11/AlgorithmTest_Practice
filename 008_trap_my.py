from typing import List

# 시간 초과..

class Solution:
    def IsWater(self, x, y, height) -> bool:
        if (height[x] >= y):
            return False
        
        left = False
        right = False
        offset = 1

        while True: #둘다 true여야 끝난다.
            if (left and right):
                print(x,y,True)
                return True
            if (left is False and x-offset < 0) or (right is False and x+offset >= len(height)):
                print(x,y,left,right,False)
                return False
            if (left is False and height[x-offset] >= y):
                left = True
            if (right is False and height[x+offset] >= y):
                right = True
            offset += 1

    def trap(self, height: List[int]) -> int:
        count = 0
        for x in range(len(height)):
            for y in range(1, max(height)+1):
                if Solution().IsWater(x,y,height):
                    count += 1
        return count
        
_height = [2,0,2]
_answer = Solution().trap(_height)

print(_answer)