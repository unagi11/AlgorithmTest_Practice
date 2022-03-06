from typing import Iterator, List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:

        _result = []

        for index, key in enumerate(temperatures):
            warmerDay = 0
            for index2, key2 in enumerate(temperatures[index+1:]):
                if key < key2:
                    warmerDay = index2 + 1
                    break
            _result.append(warmerDay)

        return _result

_input = [89,62,70,58,47,47,46,76,100,70]
print(Solution().dailyTemperatures(_input))