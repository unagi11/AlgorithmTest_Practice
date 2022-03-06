# Time Limit Exceeded

# 07/21/2021 04:11	Time Limit Exceeded	N/A	N/A	python3

from typing import List

# 섬에 연결된 모든 노드를 확인하는 작업
def CheckNearPosition(grid: List, unchecked: List, position: tuple):

	# 동서남북
	directions = [(+1,0),(-1,0),(0,+1),(0,-1)]

	for direction in directions:
		moved = (position[0] + direction[0], position[1] + direction[1])

		# 존재하지 않는 위치는 넘어간다.
		if moved[0] < 0 or moved[1] < 0 or moved[0] >= len(grid) or moved[1] >= len(grid[0]):
			continue
		# 아직 체크하지 않았고, 연결된 섬 면적이라면 이 섬도 체크해준다.
		if moved in unchecked and grid[moved[0]][moved[1]] == "1":
			unchecked.remove(moved)
			CheckNearPosition(grid, unchecked, moved)



class Solution:
	def numIslands(self, grid: List[List[str]]) -> int:

		# 확인되지 않은 노드
		unchecked = []

		# 섬의 개수
		count = 0

		for y in range(len(grid)):
			for x in range(len(grid[y])):
				unchecked.append((y,x))

		while len(unchecked) != 0:
			position = unchecked.pop()
			
			# 육지라면 연결된 노드를 확인해준다.
			if grid[position[0]][position[1]] == "1":
				count += 1
				CheckNearPosition(grid, unchecked, position)

			# 육지가 아니라면 연결된 노드 확인 없이 그냥 체크한다
			else:
				pass

		return count


grid = [
	["1","1","0","0","0"],
	["1","1","0","0","0"],
	["0","0","1","0","0"],
	["0","0","0","1","1"]
]

print(Solution().numIslands(grid))
