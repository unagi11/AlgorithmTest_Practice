# 문제 이해가 안됨

class Solution:
    def removeDuplicateLetters(self, s: str) -> str:

        _set = list(set(s))
        _dict = {}

        for i in _set:
            _dict.setdefault(i, 0)

        for i in list(s):
            _dict[i] += 1

        _set = sorted(_set, key = lambda value: (value, _dict[value]))

        return _set


print(Solution().removeDuplicateLetters("cbacdcbc"))
