# 숫자 하나씩 따져보는 방식, 실패. 병합으로 풀어야하나봄

from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        intervals = sorted(intervals, key= lambda x : x[1])
        max = intervals[-1][1]
        intervals = sorted(intervals)
        min = intervals[0][0]

        print(min,max)

        include = set()

        index = 0

        for i in range(min, max):
            # 오른쪽 범위가 현재 i 보다 커야한다.
            while intervals[index][1] - 1 < i:
                index += 1

            # print(intervals[index], i)

            if intervals[index][0] <= i and i < intervals[index][1]:
                include.add(i)

        print(include)

        answer = []
        right, left = None, None

        for i in include:
            if right == i:
                right = i + 1
            else:
                if left != None:
                    answer.append([left, right])
                left = i
                right = i + 1

        answer.append([left, right])

        return answer

# intervals = [[1,3],[2,6],[8,10],[15,18]]
# intervals = [[1,4],[4,5]]

intervals = [[1,4],[2,3]]
print(Solution().merge(intervals))