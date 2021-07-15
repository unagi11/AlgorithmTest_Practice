from typing import Iterator, List
import sys

# Success
# Details 
# Runtime: 2016 ms, faster than 5.08% of Python3 online submissions for Daily Temperatures.
# Memory Usage: 25.6 MB, less than 16.56% of Python3 online submissions for Daily Temperatures.

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:

        _result = []
        _stack = []

        for index, key in enumerate(temperatures[:len(temperatures)-1]):

            # 현재보다 다음 온도가 더 낮아진다면, 스텍에 넣는다.
            if temperatures[index] >= temperatures[index+1]:
                # 스텍에 넣는다.
                _result.append(0)
                _stack.append((index, key))
            # 현재보다 다음 온도가 더 높으면
            else:
                # 1을 넣어준다.
                _result.append(1)
                # 스텍을 처리해줘야 한다.
                while _stack:
                    s_index, s_key = _stack.pop()

                    if s_key < temperatures[index+1]:
                        _result[s_index] = index+1 - s_index
                    else:
                        _stack.append((s_index, s_key))
                        break

        
        _result.append(0)
        
        return _result



_input = [73,74,75,71,69,72,76,73]
print(Solution().dailyTemperatures(_input))