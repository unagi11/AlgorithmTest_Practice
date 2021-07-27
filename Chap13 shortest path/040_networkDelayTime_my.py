# Success
# Details 
# Runtime: 476 ms, faster than 61.44% of Python3 online submissions for Network Delay Time.
# Memory Usage: 16.8 MB, less than 7.86% of Python3 online submissions for Network Delay Time.

from typing import Collection, List
import sys
import heapq

# 다익스트라로 풀어봐야겠다.


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:

        graph = {i: [] for i in range(1, n+1)}
        weight = {(i, j): -1 for i in range(1, n+1) for j in range(1, n+1)}

        for time in times:
            graph[time[0]].append(time[1])
            weight[(time[0], time[1])] = time[2]

        fromKtoWeight = {i: sys.maxsize for i in range(1, n+1)}
        visited = {i: False for i in range(1, n+1)}
        canGo = set()

        # 자기 자신으로 가는 것은 0 이다.
        curWeight = 0
        curNode = k
        canGo.add(curNode)

        while canGo:
            # print(canGo, fromKtoWeight, curNode)
            canGo.remove(curNode)
            visited[curNode] = True

            # 현재 노드 weight 설정
            fromKtoWeight[curNode] = curWeight

            # 현재 노드 기준으로 weight 설정
            for node in graph[curNode]:
                if visited[node] is False:
                    fromKtoWeight[node] = curWeight + weight[(curNode, node)] if fromKtoWeight[node] > curWeight + weight[(curNode, node)] else fromKtoWeight[node]
                    canGo.add(node)

            # 갈수 있는 노드들 중에서 weight가 가장 적은 값을 고른다.
            curWeight = sys.maxsize
            for nextGo in canGo:
                if curWeight > fromKtoWeight[nextGo]:
                    curWeight = fromKtoWeight[nextGo]
                    curNode = nextGo
    
        # print(canGo, fromKtoWeight, curNode)
        # -1 값이 하나라도 존재한다면
        if sys.maxsize in fromKtoWeight.values():
            return -1
        # -1 값이 하나도 존재하지 않는다면 최대값을 리턴한다.
        else:
            return max(fromKtoWeight.values())


_times, _n, _k = [[1,2,1],[2,3,2],[1,3,2]],3,1

print(Solution().networkDelayTime(_times, _n, _k))
