from typing import List
import re

class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph = re.sub("[^a-zA-Z0-9]", " ", paragraph)
        _split = paragraph.split()
        _dict = {}
        for index in _split:
            index = index.lower()
            if index not in _dict:
                _dict[index] = 1
            else:
                _dict[index] += 1
        biggest = ["", 0]
        for index in _dict:
            if (index not in banned and _dict[index] > biggest[1]):
                biggest[0] = index
                biggest[1] = _dict[index]
        return biggest[0]


_paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
_banned = ["hit"]    


print(Solution().mostCommonWord(_paragraph, _banned))