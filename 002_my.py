class Solution:
    @staticmethod
    def reverseString(s) -> None:
        # s.reverse()
        s[:] = s[::-1]


_input = list(input())
Solution().reverseString(_input)

print(_input)
