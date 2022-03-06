# Time Limit Exceeded
# 07/22/2021 14:11	Time Limit Exceeded	N/A	N/A	python3

from typing import Dict, List
import copy

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:

        # 현재 갈수있는 노드 정보를 딕셔너리로 기록한다.
        graph = dict()
        
        for ticket in tickets:
            graph.setdefault(ticket[0], [])
            graph.setdefault(ticket[1], [])
            graph[ticket[0]].append(ticket[1])
        
        # dict의 value들을 정렬해줍니다.
        for i in graph:
            graph[i].sort(reverse = True)

        route = []
        def dfs(node:str):
            print(node, graph, graph[node])
            while graph[node]:
                dfs(graph[node].pop())
            # 리프 노드에서 넣어준다.
            route.append(node)
            print(route)

        dfs("JFK")

        return route[::-1]
        
_input = [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
# _input = [
#     ["JFK", "SFO"],
#     ["JFK", "ATL"],
#     ["SFO", "ATL"],
#     ["ATL", "JFK"],
#     ["ATL", "SFO"]
# ]
print(Solution().findItinerary(_input))