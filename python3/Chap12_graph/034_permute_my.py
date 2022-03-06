# Success
# Details 
# Runtime: 44 ms, faster than 41.98% of Python3 online submissions for Permutations.
# Memory Usage: 14.5 MB, less than 14.77% of Python3 online submissions for Permutations.

from typing import List

class Solution:
	def permute(self, nums: List[int]) -> List[List[int]]:
		ans = []

		def recurFunc(arr: List[int], numList: List[int]):

			# print(arr, numList)

			# 리프 노드에 도달하면
			if (len(numList) == 1):
				# 마지막 문자를 숫자 배열에 추가해주고
				arr.append(numList[0])
				# 숫자 배열을 정답 리스트에 추가해준다.
				ans.append(arr)

			else:
				for i in numList:
					# 숫자 배열에 i를 추가하고
					copyArr = arr[:]
					copyArr.append(i)
					
					# 남은 숫자 리스트를 갱신한다.
					copyList = numList[:]
					copyList.remove(i)

					# 다음 재귀로 보낸다.
					recurFunc(copyArr, copyList)
		
		recurFunc([], nums)

		return ans

print(Solution().permute([1,2,3]))