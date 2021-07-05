class Solution:
    def isPalindrome(self, s: str) -> bool:
        change = ""
        for i in s:
            if (i.isalpha() is False and i.isdigit() is False):
                continue
            else:
                change += i.lower()        
        print(change)
        for index in range(len(change) // 2):
            if (change[index] == change[-index-1]) is False:
               return False
        return True

_input = input()
_output = Solution().isPalindrome(_input)

print(_output)