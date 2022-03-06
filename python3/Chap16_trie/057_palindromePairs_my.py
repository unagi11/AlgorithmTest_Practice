# 부르트 포스 시간초과 실패

from typing import List

class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:

        pairs = []

        for key1, item1  in enumerate(words):
            for key2, item2 in enumerate(words):
                if item1 == item2:
                    continue
                
                temp = item1 + item2
                if temp == temp[::-1]:
                    pairs.append([key1, key2])

        return pairs


words = ["abcd","dcba","lls","s","sssll"]
print(Solution().palindromePairs(words))