class Solution:
    def reverseString(self, s) -> None:
        #s.reverse()
        s[:] = s[::-1]

_input = list(input())
_output = Solution().reverseString(_input)

print(_output)