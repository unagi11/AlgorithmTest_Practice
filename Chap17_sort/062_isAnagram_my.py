# Success
# Details 
# Runtime: 48 ms, faster than 69.17% of Python3 online submissions for Valid Anagram.
# Memory Usage: 15.3 MB, less than 5.20% of Python3 online submissions for Valid Anagram.

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        s = sorted(list(s))
        t = sorted(list(t))

        return s == t

s = "anagram"
t = "nagaram"

print(Solution().isAnagram(s,t))