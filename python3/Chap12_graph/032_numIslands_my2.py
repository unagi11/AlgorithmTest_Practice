# Success
# Details 
# Runtime: 176 ms, faster than 23.78% of Python3 online submissions for Number of Islands.
# Memory Usage: 22.7 MB, less than 5.44% of Python3 online submissions for Number of Islands.

from typing import Dict, List

# 섬에 연결된 모든 노드를 확인하는 작업
def CheckNearPosition(grid: List, unchecked: Dict, position):

	# 동서남북
	directions = [(+1,0),(-1,0),(0,+1),(0,-1)]

	for direction in directions:
		moved = (position[0] + direction[0], position[1] + direction[1])

		# 존재하지 않는 위치는 넘어간다.
		if moved[0] < 0 or moved[1] < 0 or moved[0] >= len(grid) or moved[1] >= len(grid[0]):
			continue
		
		# 아직 체크하지 않았고, 연결된 섬 면적이라면 이 섬도 체크해준다.
		if moved in unchecked and grid[moved[0]][moved[1]] == "1":
			temp = unchecked.pop(moved)
			CheckNearPosition(grid, unchecked, moved)



class Solution:
	def numIslands(self, grid: List[List[str]]) -> int:

		# 확인되지 않은 노드
		unchecked = {}

		# 섬의 개수
		count = 0

		for y in range(len(grid)):
			for x in range(len(grid[y])):
				unchecked[(y,x)] = True

		while len(unchecked) != 0:
			position = unchecked.popitem()[0]
			
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
