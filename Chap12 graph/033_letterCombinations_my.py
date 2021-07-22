# Success
# Details 
# Runtime: 28 ms, faster than 85.96% of Python3 online submissions for Letter Combinations of a Phone Number.
# Memory Usage: 14.4 MB, less than 31.21% of Python3 online submissions for Letter Combinations of a Phone Number.

from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:

        numToDigits = {
            "1" : "",
            "2" : "abc",
            "3" : "def",
            "4" : "ghi",
            "5" : "jkl",
            "6" : "mno",
            "7" : "pqrs",
            "8" : "tuv",
            "9" : "wxyz"
        }

        if len(digits) == 0:
            return ""

        _list = list(numToDigits[digits[0]])
        if len(digits) == 1:
            return _list

        def AddChar(strList, nextStr) -> List[str]:

            newlist = []

            for c in list(nextStr):
                for s in strList:
                    newlist.append(s + c)

            return newlist

        for d in digits[1:]:
            _list = AddChar(_list, numToDigits[d])

        return _list

print(Solution().letterCombinations("23"))