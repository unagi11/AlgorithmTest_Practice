# sol2 코드 뺏긴거임
# Success
# Details 
# Runtime: 100 ms, faster than 56.73% of Python3 online submissions for Course Schedule.
# Memory Usage: 18 MB, less than 5.11% of Python3 online submissions for Course Schedule.
from typing import List

# 위상정렬 방법도 있다.

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = {i : [] for i in range(numCourses)}

        for item in prerequisites:
            graph[item[0]].append(item[1])

        print(graph)

        path = set()
        visited = set()

        # 순환 구조임을 검사한다.
        def dfs(cur):

            if cur in path:
                return False

            if cur in visited:
                return True

            path.add(cur)
            for next in graph[cur]:
                if dfs(next) == False:
                    return False
                else:
                    continue
            path.remove(cur)
            # cur은 전부 확인이 된 보증된 노드이다
            # cur은 이미 전부 돌았는데도, False가 나오지 않은것이 확인되었으므로
            # cur로 가는 루트는 더이상 확인할 필요가없다.
            visited.add(cur)

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