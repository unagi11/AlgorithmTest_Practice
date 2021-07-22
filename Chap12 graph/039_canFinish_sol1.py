# 사실 sol1 코드 뺏긴거임

from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = {i : [] for i in range(numCourses)}

        for item in prerequisites:
            graph[item[0]].append(item[1])

        print(graph)

        path = set()

        # 순환 구조임을 검사한다.
        def dfs(cur):

            if cur in path:
                return False

            path.add(cur)
            for next in graph[cur]:
                if dfs(next) == False:
                    return False
                else:
                    continue
            path.remove(cur)

            return True

        # 한 노드라도 순환 구조라면 False
        for key in list(graph):
            if dfs(key) is False:
                return False
            else:
                continue
        
        # 전부 순환 구조가 아니라면 True
        return True

_input1 = 5
_input2 = [[1,4],[2,4],[3,1],[3,2]]

print(Solution().canFinish(_input1, _input2))