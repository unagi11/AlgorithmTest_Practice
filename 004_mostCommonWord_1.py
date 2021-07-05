from typing import List
import re
from collections import Counter


class Solution:
    @staticmethod
    def mostCommonWord(paragraph: str, banned: List[str]) -> str:
        words = [word for word in re.sub(r'[^\w]', ' ', paragraph).lower().split()
                 if word not in banned]

        counts = Counter(words)
        return counts.most_common(1)[0][0]


_paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
_banned = ["hit"]

print(Solution().mostCommonWord(_paragraph, _banned))
