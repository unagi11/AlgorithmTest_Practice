from typing import Collection, List
import collections
import copy
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:

        graph = collections.defaultdict(list)

        for i in edges:
            graph[i[0]].append(i[1])
            graph[i[1]].append(i[0])

        # BFS순회 후에 해당 노드와 최대 깊이를 기록한다.
        data = []

        for start in range(n):
            expand = {start}
            visited = set()
            depth = 0
            while expand:

                temp = set()
                
                for i in expand:
                    visited.add(i)
                    for j in graph[i]:
                        if j not in visited:
                            temp.add(j)
                
                expand = temp
                depth += 1
            
            data.append((start, depth))

        data = sorted(data, key= lambda x: x[1])
        data = [item[0] for item in data if item[1] == data[0][1]]

        return data


n  = 4
edges = [[1,0],[1,2],[1,3]]
print(Solution().findMinHeightTrees(n, edges))
    
