from typing import List

# 미완성 코드.. 실패

class Box:
    x = 0
    y = 0
    def __init__ (self, x, y):
        self.x, self.y = x, y
    isWater = False
    isBlock = False
    left = False
    right = False

    def __str__ (self):
        return '({}, {}, B : {}, W : {})'.format(self.x, self.y, self.isBlock, self.isWater)

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


        world = [[Box(x,y) for x in range(len(height)) ] for y in range(max(height))]



        for x in range(len(height)):
            for y in range(height[x]):
                world[y][x].isBlock = True

        offset = 1

        # for 행 in world[::-1]: #맨위 행부터 한다.
        #     leftblock=
        #     for block in 행:
        #         if block


        # count = 0
        # for x in range(len(height)):
        #     for y in range(1, max(height)+1):
        #         if Solution().IsWater(x,y,height):
        #             count += 1
        return 1
        
_height = [2,0,2]
_answer = Solution().trap(_height)

print(_answer)