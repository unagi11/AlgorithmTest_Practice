
from typing import List

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:

        # 현재 갈수있는 노드 정보를 딕셔너리로 기록한다.
        graph = dict()
        
        for ticket in tickets:
            graph.setdefault(ticket[0], [])
            graph.setdefault(ticket[1], [])
            graph[ticket[0]].append(ticket)
        for i in graph:
            graph[i].sort()

        print(graph)

        # 시작 지점은 JFK
        curNode = "JFK"
        curPath = []

        # 확인해본 모든 Path 기록
        exploredPaths = []

        # 현재 노드에서 확장될수 있는 다음 노드들의 집합
        frontierTickets = []

        while True:

            # 정답이다 연금술사
            if len(curPath) == len(tickets):
                answer = [n[1] for n in curPath]
                answer.insert(0, "JFK")
                return answer

            # curNode 변화 감지용 (모든 노드 부적합 탐지용)
            temp = curNode

            # 프론티어 노드 집합 갱신
            frontierTickets = graph[curNode]
            # print(curNode , ">", frontierNodes)

            # 순회
            for nextTicket in frontierTickets:
                nextPath = curPath[:]
                nextPath.append(nextTicket)

                # 만약 다음으로 시험해볼 path가 경험한 경로들중에 존재하면 
                # 다음 경로로 넘어간다.
                if nextTicket in curPath or nextPath in exploredPaths:
                    continue
                # 시험해보지 않은 path라면 curNode, curPath를 갱신하고 exploredPaths에 추가한다.
                else:
                    curNode = nextTicket[1]
                    curPath.append(nextTicket)
                    exploredPaths.append(curPath[:])
                    break
            
            # 만약 현재 노드에서 시험해볼 모든 path가 부적합하다면
            # 한 노드를 거슬러 올라간다.
            if temp == curNode and len(curPath) != 0:
                print(curNode, curPath)
                curNode = curPath[-1][0]
                curPath.pop()

_input = [["EZE","AXA"],["TIA","ANU"],["ANU","JFK"],["JFK","ANU"],["ANU","EZE"],["TIA","ANU"],["AXA","TIA"],["TIA","JFK"],["ANU","TIA"],["JFK","TIA"]]

print(Solution().findItinerary(_input))