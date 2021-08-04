# 뇌피셜 최적화. 더 느려짐

from typing import List

class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:

        pairs = []

        offset = 10

        for key1, item1 in enumerate(words):
            for key2, item2 in enumerate(words):
                if key1 == key2:
                    continue

                temp = item1 + item2
                _len = len(temp)

                isbreaked = False

                for i in range(0, _len // 2 + 1, offset):
                    # print(temp, ":", temp[i:i+offset], i, i+offset, temp[-i-1:-(i+offset)-1:-1],-i-1, -(i+offset)-1)
                    if temp[i:i+offset:1] != temp[-(i+1):-(i+offset+1):-1]:
                        isbreaked = True
                        break
                
                if isbreaked:
                    continue
                else:
                    pairs.append([key1, key2])

        return pairs


words = ["abcd", "dcba", "lls", "s", "sssll"]
print(Solution().palindromePairs(words))
