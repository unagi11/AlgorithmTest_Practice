# Time Limit Exceeded
# 07/22/2021 14:11	Time Limit Exceeded	N/A	N/A	python3

from typing import Dict, List
import copy

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:

        # 현재 갈수있는 노드 정보를 딕셔너리로 기록한다.
        canGo = dict()
        
        for ticket in tickets:
            canGo.setdefault(ticket[0], [])
            canGo.setdefault(ticket[1], [])
            canGo[ticket[0]].append(ticket[1])
        
        # dict의 value들을 정렬해줍니다.
        for i in canGo:
            canGo[i].sort()

        print(canGo)

        # 시작 지점은 JFK
        start = "JFK"
        path = ["JFK"]

        ans = []

        def dfs(graph: Dict, curPath: list, curNode: str):

            # print(curPath, curNode, graph[curNode])

            # 임무 완료
            if len(curPath) == len(tickets) + 1:
                ans.append(curPath)
                return
            # 현재 위치에서 갈수 있는길이 존재하지 않음
            elif len(graph.get(curNode)) == 0:
                return
            # 완료도 아니고 갈수있는길이 없지도 않으면 다시한번 재귀
            else:
                for nextNode in graph[curNode]:
                    newgraph = copy.deepcopy(graph)
                    newgraph[curNode].remove(nextNode)
                    
                    newpath = curPath[:]
                    # print("c", curNode, "n", nextNode)
                    newpath.append(nextNode)

                    dfs(newgraph, newpath, nextNode)

        dfs(canGo, path, start)

        return ans[0]
_input = [["AXA","EZE"],["EZE","AUA"],["ADL","JFK"],["ADL","TIA"],["AUA","AXA"],["EZE","TIA"],["EZE","TIA"],["AXA","EZE"],["EZE","ADL"],["ANU","EZE"],["TIA","EZE"],["JFK","ADL"],["AUA","JFK"],["JFK","EZE"],["EZE","ANU"],["ADL","AUA"],["ANU","AXA"],["AXA","ADL"],["AUA","JFK"],["EZE","ADL"],["ANU","TIA"],["AUA","JFK"],["TIA","JFK"],["EZE","AUA"],["AXA","EZE"],["AUA","ANU"],["ADL","AXA"],["EZE","ADL"],["AUA","ANU"],["AXA","EZE"],["TIA","AUA"],["AXA","EZE"],["AUA","SYD"],["ADL","JFK"],["EZE","AUA"],["ADL","ANU"],["AUA","TIA"],["ADL","EZE"],["TIA","JFK"],["AXA","ANU"],["JFK","AXA"],["JFK","ADL"],["ADL","EZE"],["AXA","TIA"],["JFK","AUA"],["ADL","EZE"],["JFK","ADL"],["ADL","AXA"],["TIA","AUA"],["AXA","JFK"],["ADL","AUA"],["TIA","JFK"],["JFK","ADL"],["JFK","ADL"],["ANU","AXA"],["TIA","AXA"],["EZE","JFK"],["EZE","AXA"],["ADL","TIA"],["JFK","AUA"],["TIA","EZE"],["EZE","ADL"],["JFK","ANU"],["TIA","AUA"],["EZE","ADL"],["ADL","JFK"],["ANU","AXA"],["AUA","AXA"],["ANU","EZE"],["ADL","AXA"],["ANU","AXA"],["TIA","ADL"],["JFK","ADL"],["JFK","TIA"],["AUA","ADL"],["AUA","TIA"],["TIA","JFK"],["EZE","JFK"],["AUA","ADL"],["ADL","AUA"],["EZE","ANU"],["ADL","ANU"],["AUA","AXA"],["AXA","TIA"],["AXA","TIA"],["ADL","AXA"],["EZE","AXA"],["AXA","JFK"],["JFK","AUA"],["ANU","ADL"],["AXA","TIA"],["ANU","AUA"],["JFK","EZE"],["AXA","ADL"],["TIA","EZE"],["JFK","AXA"],["AXA","ADL"],["EZE","AUA"],["AXA","ANU"],["ADL","EZE"],["AUA","EZE"]]
# _input = [
#     ["JFK", "SFO"],
#     ["JFK", "ATL"],
#     ["SFO", "ATL"],
#     ["ATL", "JFK"],
#     ["ATL", "SFO"]
# ]
print(Solution().findItinerary(_input))