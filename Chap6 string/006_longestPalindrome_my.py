class Solution:

    def longestPalindrome(self, s: str) -> str:
        leftLimit = 0
        rightLimit = (len(s) - 1) * 2 + 1
        
        all_palindrome = []
        # print("left", leftLimit, ", right", rightLimit)
                
        for _pivot in range(leftLimit, rightLimit):
            left = _pivot
            right = _pivot + 1
            
            while left >= leftLimit and right <= rightLimit:
                slice = s[left//2:right//2+1]
                if (slice == slice[::-1]):
                    all_palindrome.append(slice)
                    left -= 2
                    right += 2
                else :
                    break
              
        all_palindrome = sorted(all_palindrome, key = len)  
        all_palindrome.reverse()
        
        return all_palindrome[0]
#    b   a   b   a   d
# -1 0 1 2 3 4 5 6 7 8 9
        
_input = "aaaaaaaaaaaaa"
_output = Solution().longestPalindrome(_input)

print(_output)