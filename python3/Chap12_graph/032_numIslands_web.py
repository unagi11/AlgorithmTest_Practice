from typing import Dict, List

class Solution:
	def numIslands(self, grid: List[List[str]]) -> int:

		def is_land(grid, next_loc):

			(x, y) = next_loc

			grid[x][y] = '0'

			if x+1 < rows and grid[x+1][y] == '1':
				grid = is_land(grid, (x+1, y))

			if x - 1 >= 0 and grid[x-1][y] == '1':
				grid = is_land(grid, (x-1, y))

			if y+1 < cols and grid[x][y+1] == '1':
				grid = is_land(grid, (x, y+1))

			if y-1 >= 0 and grid[x][y-1] == '1':
				grid = is_land(grid, (x, y-1))

			return grid

		rows = len(grid)
		cols = len(grid[0])
		ans = 0
		for row in range(rows):
			for col in range(cols):
				if grid[row][col] == '1':
					grid = is_land(grid, (row, col))
					ans += 1
		return ans
