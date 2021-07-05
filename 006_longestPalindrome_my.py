class Solution:

    @staticmethod
    def longestPalindrome(s: str) -> str:
        left_limit = 0
        right_limit = (len(s) - 1) * 2 + 1

        all_palindrome = []
        # print("left", left_limit, ", right", right_limit)

        for _pivot in range(left_limit, right_limit):
            left = _pivot
            right = _pivot + 1

            while left >= left_limit and right <= right_limit:
                sliced = s[left // 2:right // 2 + 1]
                if sliced == sliced[::-1]:
                    all_palindrome.append(sliced)
                    left -= 2
                    right += 2
                else:
                    break

        all_palindrome = sorted(all_palindrome, key=len)
        all_palindrome.reverse()

        return all_palindrome[0]


#    b   a   b   a   d
# -1 0 1 2 3 4 5 6 7 8 9

_input = "aaaaaaaaaaaaa"
_output = Solution().longestPalindrome(_input)

print(_output)
