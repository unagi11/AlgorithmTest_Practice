class Solution:
    @staticmethod
    def longestPalindrome(s: str) -> str:
        left_limit = 0
        right_limit = (len(s) - 1) * 2 + 1

        all_palindrome = []

        _extends = 0

        for _pivot in range(left_limit, right_limit):
            left = _pivot - _extends
            right = _pivot + 1 + _extends
            while True:
                slice = s[left // 2:right // 2 + 1]
                if slice == slice[::-1] and (left >= left_limit and right <= right_limit):

                    all_palindrome.append(slice)
                    _extends += 2
                    left = _pivot - _extends
                    right = _pivot + 1 + _extends
                else:
                    _extends -= 2
                    break

        all_palindrome = sorted(all_palindrome, key=len)
        all_palindrome.reverse()

        return all_palindrome[0]


_input = "aaaaaaa"
_output = Solution().longestPalindrome(_input)

print(_output)
