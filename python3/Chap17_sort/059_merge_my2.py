# 병합도 실패

from typing import List

class Solution:
    def mergeTwoList(self, l1: List[List[int]], l2:List[List[int]]) -> List[List[int]]:

        if not l1 or not l2:
            return l1 or l2

        l3 = []


        for i in l1:
            merged = False
            for j in l2:
                if i[0] > j[0]:
                    i, j = j, i
                left = i[0]
                # 겹칠수 있다.
                if i[1] >= j[0]:
                    merged = True
                    if i[1] > j[1]:
                        right = i[1]
                    else:
                        right = j[1]
                    if [left, right] not in l3:
                        l3.append([left, right])
                else:
                    l3.append(j)
            if not merged:
                l3.append(i)

        # print(l1,",", l2, ",",l3)
        return l3


    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        intervals.sort()

        def divide(intervals):
            if not intervals or len(intervals) == 1:
                return intervals
            
            half = len(intervals) // 2

            print(intervals[:half], intervals[half:])

            l1 = divide(intervals[:half])
            l2 = divide(intervals[half:])

            return self.mergeTwoList(l1, l2)
        
        return divide(intervals)

intervals = [[2,3],[4,5],[6,7],[8,9],[1,10]]
# intervals = [[2,3],[5,5],[2,2],[3,4],[3,4]]
# intervals = [[1,3],[2,6],[8,10],[15,18]]
# intervals = [[1,4],[4,5]]

# intervals = [[1,4],[2,3]]
print(Solution().merge(intervals))