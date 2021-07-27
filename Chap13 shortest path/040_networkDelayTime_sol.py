import collections
import heapq
from typing import List


class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        graph = collections.defaultdict(list)
        # 그래프 인접 리스트 구성
        for u, v, w in times:
            graph[u].append((v, w))

        # 큐 변수: [(소요 시간, 정점)]
        Q = [(0, K)]
        # 확정된 최소 도달 비용
        dist = collections.defaultdict(int)

        # 우선 순위 큐 최소값 기준으로 정점까지 최단 경로 삽입
        while Q:
            # 힙에서 소요시간이 가장 적은 노드를 뺀다.
            time, node = heapq.heappop(Q)

            # 노드가 dist 배열에 없다면
            if node not in dist:
                # dist 배열에 시간을 기록한다.
                dist[node] = time
                # 현 노드와 연결된 노드들
                for v, w in graph[node]:
                    # 현재 시간과 더해서
                    alt = time + w
                    # 힙에 넣어준다.
                    heapq.heappush(Q, (alt, v))
            # dist 배열에 있으면 이미 최소값이기 때문에 넘어간다.

        # 모든 노드 최단 경로 존재 여부 판별
        if len(dist) == N:
            return max(dist.values())
        return -1

_times, _n, _k = [[1,2,1],[2,3,2],[1,3,2]],3,1

print(Solution().networkDelayTime(_times, _n, _k))
